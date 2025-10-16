tam_max = 5

lista_Matricula = [None] * tam_max 
lista_nome = [None] * tam_max
lista_email = [None] * tam_max
lista_curso = [None] * tam_max

cont_aluno = 0

while True:

    print('1 - Cadastrar um Aluno')
    print('2 - Pesquisar um Aluno')
    print('3 - Listagem dos Alunos')
    print('4 - Sair do Sistema')

    op = int(input("Digite sua opção: "))

    if op == 1:
        print("Cadastrar")
        mat = int(input("Digite a matricula: "))
        nome = input("Digite o nome: ")
        email = input("Digite o Email: ")
        curso = input("Digite o Curso: ")

        lista_Matricula[cont_aluno] = mat
        lista_nome[cont_aluno] = nome
        lista_email[cont_aluno] = email
        lista_curso[cont_aluno] = curso
        cont_aluno += 1
        print(lista_nome)
        print(lista_email)
        print(lista_Matricula)


    elif op == 2:
        print("Pesquisar")
    elif op == 3:
        print("Listagem")
    elif op == 4:
        print("Saindo do Sistema!")
        break
    else:
        print("Opção inválida!")
