CREATE TABLE Departamentos (
    depto_codigo INT PRIMARY KEY,
    depto_sigla VARCHAR(10) NOT NULL,
    depto_nome VARCHAR(100),
    depto_diretor VARCHAR(100),
);

=========================================

INSERT INTO Departamentos (depto_codigo, depto_sigla, depto_nome, depto_diretor)
VALUES (1, 'CCSA', 'Centro de Ciências Sociais Aplicadas', 'Prof. Dr. Marcelo Vargas'),
       (2, 'CCHE', 'Centro de Ciências Humanas e da Educação', 'Prof. Ms. José Ricardo dos Santos');