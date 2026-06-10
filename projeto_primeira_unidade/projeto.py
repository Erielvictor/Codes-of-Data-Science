import datetime
class Banco:
    nome_banco = "Bradesco"
    data_hora = datetime.datetime.now()
    lista_clientes = []

    @classmethod
    def mudar_nome(cls, novoNome):
        cls.nome_banco = novoNome

    def __init__(self, nome, nmrConta: str, saldo):
        self.nome = nome
        self.nmrConta = nmrConta
        self.saldo = saldo

        Banco.lista_clientes.append(self)
        
    @classmethod
    def pagar_todos(cls, valor_fixo, data_pagamento, cliente_atrasado):
        for cliente in cls.lista_clientes:
            cliente.saldo += valor_fixo
            
            if cliente == cliente_atrasado:
                data_atrasada = data_pagamento + datetime.timedelta(days=1)
                print(f"Pagamento de R$ {valor_fixo} para {cliente.nome} agendado para {data_atrasada.strftime('%d/%m/%Y')}.")
            else:
                print(f"Pagamento de R$ {valor_fixo} para {cliente.nome} realizado em {data_pagamento.strftime('%d/%m/%Y')}.")
            

    def mostrar_saldo(self):
        return f"O cliente: {self.nome}, possui um saldo de R$ {self.saldo} TIME: {self.data_hora}"

    def sacar(self, valor):
        if valor < self.saldo:
            self.saldo -= valor
        else:
            return f"O cliente: {self.nome}, não pode realizar um saque com valor maior que o saldo | TIME: {self.data_hora}"

        return f"O cliente: {self.nome}, realizou um saque de R$ {valor} TIME: {self.data_hora}"

    def transferir(self, valor, clienteDestino):
        if valor < self.saldo:
            self.saldo -= valor
            clienteDestino.saldo += valor
            return f"O cliente: {self.nome}, realizou uma transfêrencia de R$ {valor}  para {clienteDestino.nome} | TIME: {self.data_hora}"
        else:
            return f"Erro: Saldo insuficiente para o cliente {self.nome}."

    def gerar_extrato(self):
        return f"Cliente: {self.nome} | Agência: {self.nmrConta} | Saldo: R$ {self.saldo} | TIME: {self.data_hora}"


cliente1 = Banco("João", "0001", 5000)
cliente2 = Banco("Maria", '0002', 5000)
print(30 * "-")
print(cliente1.mostrar_saldo())
print(30 * "-")
print(cliente1.gerar_extrato())
print(30 * "-")
print(cliente1.transferir(1000, cliente2))
print(30 * "-")
print(cliente1.mostrar_saldo())
print(30 * "-")
print(cliente2.mostrar_saldo())

data_hoje = datetime.datetime.now()
print(30 * "-")
Banco.pagar_todos(500, data_hoje, cliente2)
