import datetime


class Banco:
    nome_banco = 'Bradesco'
    data_hora = datetime.datetime.now()
    lista_clientes = []
   
    @classmethod
    def mudar_nome(cls, novoNome):
        cls.nome_banco = novoNome
    
    def __init__(self, nome, nmrConta:str, saldo):
        self.nome = nome
        self.nmrConta = nmrConta
        self.saldo = saldo
        
    def mostrar_saldo(self):
        return f'O cliente: {self.nome}, possui um saldo de R$ {self.saldo} TIME: {self.data_hora}'
    
    def sacar(self, valor):
        if valor < self.saldo:
            self.saldo -= valor
        else:
            return f'O cliente: {self.nome}, não pode realizar um saque com valor maior que o saldo TIME: {self.data_hora}'
        
        return f'O cliente: {self.nome}, realizou um saque de R$ {valor} TIME: {self.data_hora}'
        
    def transferir(self, valor, clienteDestino):
        if valor < self.saldo:
            self.saldo -= valor
            clienteDestino.saldo += valor
            return f'O cliente: {self.nome}, realizou uma transfêrencia de R$ {valor}  para {clienteDestino}TIME: {self.data_hora}'
        else:
            return f'Erro: Saldo insuficiente para o cliente {self.nome}.'
        
    def gerar_extrato(self):
        return f"Cliente: {self.nome} | Agência: {self.nmrConta} | Saldo: R$ {self.saldo} | TIME: {self.data_hora}"
        
            
        
        


cliente1 = Banco("Eriel", '0001' , 5000)
cliente1.mostrar_saldo()

data_hoje = datetime.datetime.now()