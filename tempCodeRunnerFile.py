# Exemplo de uso da classe
qtd_letras = 5
alfabeto = ['a', 'b', 'c', 'd', 'e']
alfabeto_aux = ['x', 'y', 'z']
qtd_estados = 3
estado_inicial = 'q0'
qtd_estados_finais = 1
estado_final = ['q2']
marcador_inicio = '>'
marcador_final = '<'

automato = Automato(qtd_letras, alfabeto, alfabeto_aux, qtd_estados, estado_inicial, qtd_estados_finais, estado_final, marcador_inicio, marcador_final)
print(automato)
