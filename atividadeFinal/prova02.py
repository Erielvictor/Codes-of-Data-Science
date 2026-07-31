"""
Atividade final - Contas bancárias com herança e classe abstrata.

- Conta: classe abstrata com saque, depósito, transferência, cartão de
  crédito, cheque especial, extrato e fatura do cartão.
- Conta_A: cheque especial de R$ 3.000,00 e limite de cartão de R$ 10.000,00
- Conta_B: cheque especial de R$ 5.000,00 e limite de cartão de R$ 20.000,00
"""

from abc import ABC, abstractmethod
from datetime import datetime


class SaldoInsuficienteError(Exception):
    pass


class LimiteCartaoExcedidoError(Exception):
    pass


class Compra:
    def __init__(self, descricao, categoria, valor, data_hora=None):
        self.descricao = descricao
        self.categoria = categoria
        self.valor = valor
        self.data_hora = data_hora or datetime.now()

    def __str__(self):
        data_str = self.data_hora.strftime("%d/%m/%Y %H:%M")
        return (
            f"{data_str} | {self.descricao:<22} | "
            f"{self.categoria:<12} | R$ {self.valor:>9.2f}"
        )


class Transacao:
    def __init__(self, tipo, valor, data_hora=None, detalhe=""):
        self.tipo = tipo
        self.valor = valor
        self.data_hora = data_hora or datetime.now()
        self.detalhe = detalhe

    def __str__(self):
        data_str = self.data_hora.strftime("%d/%m/%Y %H:%M")
        sinal = "+" if self.valor >= 0 else "-"
        detalhe = f" ({self.detalhe})" if self.detalhe else ""
        return (
            f"{data_str} | {self.tipo:<16} | "
            f"{sinal}R$ {abs(self.valor):>9.2f}{detalhe}"
        )


class CartaoCredito:
    def __init__(self, limite):
        self.limite = limite
        self.compras = []

    @property
    def total_fatura(self):
        return sum(c.valor for c in self.compras)

    @property
    def limite_disponivel(self):
        return self.limite - self.total_fatura

    def comprar(self, descricao, categoria, valor):
        if valor <= 0:
            raise ValueError("O valor da compra deve ser positivo.")
        if valor > self.limite_disponivel:
            raise LimiteCartaoExcedidoError(
                f"Limite insuficiente. Disponível: R$ {self.limite_disponivel:.2f}"
            )
        compra = Compra(descricao, categoria, valor)
        self.compras.append(compra)
        return compra

    def totais_por_categoria(self):
        totais = {}
        for c in self.compras:
            totais[c.categoria] = totais.get(c.categoria, 0) + c.valor
        return totais

    def imprimir_fatura(self, titular=""):
        print("=" * 66)
        print(f"FATURA DO CARTÃO DE CRÉDITO - {titular}")
        print("=" * 66)
        if not self.compras:
            print("Nenhuma compra registrada nesta fatura.")
        else:
            for compra in self.compras:
                print(compra)
        print("-" * 66)
        print(f"Limite total.........: R$ {self.limite:>9.2f}")
        print(f"Total da fatura......: R$ {self.total_fatura:>9.2f}")
        print(f"Limite disponível....: R$ {self.limite_disponivel:>9.2f}")
        print("-" * 66)
        print("Total por categoria:")
        totais = self.totais_por_categoria()
        if not totais:
            print("  Nenhuma categoria registrada.")
        else:
            for categoria, valor in sorted(totais.items(), key=lambda x: -x[1]):
                print(f"  {categoria:<12}: R$ {valor:>9.2f}")
        print("=" * 66)
        print()


class Conta(ABC):
    """Classe abstrata que representa uma conta bancária genérica."""

    def __init__(
        self,
        titular,
        numero,
        saldo_inicial=0.0,
        limite_cheque_especial=0.0,
        limite_cartao=0.0,
    ):
        self.titular = titular
        self.numero = numero
        self._saldo = saldo_inicial
        self.limite_cheque_especial = limite_cheque_especial
        self.cartao = CartaoCredito(limite_cartao)
        self.extrato = []

    @property
    def saldo(self):
        return self._saldo

    @property
    def saldo_disponivel(self):
        """Saldo em conta + cheque especial disponível."""
        return self._saldo + self.limite_cheque_especial

    def _registrar(self, tipo, valor, detalhe=""):
        self.extrato.append(Transacao(tipo, valor, detalhe=detalhe))

    def depositar(self, valor):
        if valor <= 0:
            raise ValueError("O valor do depósito deve ser positivo.")
        self._saldo += valor
        self._registrar("Depósito", valor)
        print(f"Depósito de R$ {valor:.2f} realizado com sucesso.")

    def sacar(self, valor):
        if valor <= 0:
            raise ValueError("O valor do saque deve ser positivo.")
        if valor > self.saldo_disponivel:
            raise SaldoInsuficienteError(
                f"Saldo insuficiente (mesmo com cheque especial). "
                f"Disponível: R$ {self.saldo_disponivel:.2f}"
            )
        self._saldo -= valor
        self._registrar("Saque", -valor)
        print(f"Saque de R$ {valor:.2f} realizado com sucesso.")

    def transferir(self, valor, conta_destino):
        if not isinstance(conta_destino, Conta):
            raise TypeError("Conta de destino inválida.")
        if valor <= 0:
            raise ValueError("O valor da transferência deve ser positivo.")
        if valor > self.saldo_disponivel:
            raise SaldoInsuficienteError(
                f"Saldo insuficiente para transferência. "
                f"Disponível: R$ {self.saldo_disponivel:.2f}"
            )
        self._saldo -= valor
        conta_destino._saldo += valor
        self._registrar(
            "Transf. enviada", -valor, detalhe=f"para {conta_destino.titular}"
        )
        conta_destino._registrar(
            "Transf. recebida", valor, detalhe=f"de {self.titular}"
        )
        print(
            f"Transferência de R$ {valor:.2f} para "
            f"{conta_destino.titular} realizada com sucesso."
        )

    def comprar_no_cartao(self, descricao, categoria, valor):
        self.cartao.comprar(descricao, categoria, valor)
        print(
            f"Compra '{descricao}' de R$ {valor:.2f} "
            f"registrada no cartão ({categoria})."
        )

    def imprimir_extrato(self):
        print("=" * 66)
        print(
            f"EXTRATO DA CONTA - {self.titular} (nº {self.numero}) "
            f"- {self.tipo_conta()}"
        )
        print("=" * 66)
        if not self.extrato:
            print("Nenhuma movimentação registrada.")
        else:
            for transacao in self.extrato:
                print(transacao)
        print("-" * 66)
        print(f"Saldo atual..........................: R$ {self._saldo:>9.2f}")
        print(
            f"Cheque especial (limite).............: R$ {self.limite_cheque_especial:>9.2f}"
        )
        print(
            f"Saldo disponível (c/ cheque especial).: R$ {self.saldo_disponivel:>9.2f}"
        )
        print("=" * 66)
        print()

    def imprimir_fatura_cartao(self):
        self.cartao.imprimir_fatura(titular=self.titular)

    @abstractmethod
    def tipo_conta(self):
        """Cada subclasse deve informar o próprio tipo."""
        pass


class Conta_A(Conta):
    CHEQUE_ESPECIAL = 3000.00
    LIMITE_CARTAO = 10000.00

    def __init__(self, titular, numero, saldo_inicial=0.0):
        super().__init__(
            titular,
            numero,
            saldo_inicial=saldo_inicial,
            limite_cheque_especial=self.CHEQUE_ESPECIAL,
            limite_cartao=self.LIMITE_CARTAO,
        )

    def tipo_conta(self):
        return "Conta A"


class Conta_B(Conta):
    CHEQUE_ESPECIAL = 5000.00
    LIMITE_CARTAO = 20000.00

    def __init__(self, titular, numero, saldo_inicial=0.0):
        super().__init__(
            titular,
            numero,
            saldo_inicial=saldo_inicial,
            limite_cheque_especial=self.CHEQUE_ESPECIAL,
            limite_cartao=self.LIMITE_CARTAO,
        )

    def tipo_conta(self):
        return "Conta B"


if __name__ == "__main__":
    conta1 = Conta_A("João Silva", "0001-1", saldo_inicial=1000.00)
    conta2 = Conta_B("Maria Souza", "0002-1", saldo_inicial=2000.00)

    conta1.depositar(500)
    conta1.sacar(300)
    conta1.transferir(200, conta2)

    conta1.comprar_no_cartao("Supermercado Extra", "Mercado", 250.90)
    conta1.comprar_no_cartao("Cinema Shopping", "Lazer", 60.00)
    conta1.comprar_no_cartao("Assinatura Netflix", "Online", 39.90)
    conta1.comprar_no_cartao("Restaurante Sabor", "Restaurante", 120.50)
    conta1.comprar_no_cartao("Loja Virtual XPTO", "Online", 199.99)

    conta2.comprar_no_cartao("Padaria Pão Quente", "Mercado", 45.30)
    conta2.comprar_no_cartao("Show de Música", "Lazer", 350.00)
    conta2.comprar_no_cartao("Jantar Restaurante Bella", "Restaurante", 210.00)

    print()
    conta1.imprimir_extrato()
    conta2.imprimir_extrato()

    conta1.imprimir_fatura_cartao()
    conta2.imprimir_fatura_cartao()
