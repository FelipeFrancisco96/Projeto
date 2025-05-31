
nome = input("Digite seu nome: ")
idade = int(input("Digite sua idade:"))

import datetime
ano_atual = datetime.datetime.now().year
anos_faltando = 100 - idade
ano_100 = ano_atual = anos_faltando

print(f"{nome}, Você vai completar 100 anos no ano de {ano_100}.") 


