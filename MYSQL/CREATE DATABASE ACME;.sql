CREATE DATABASE ACME;

USE ACME;

CREATE TABLE departamento (
    numero_dept INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    descricao VARCHAR(255) NOT NULL,

    PRIMARY KEY (numero_dept)
);

CREATE TABLE localizacao_dept (
    id_localizacao INT NOT NULL AUTO_INCREMENT,
    numero_dept INT NOT NULL,
    nome_local VARCHAR(50) NOT NULL,

    PRIMARY KEY (id_localizacao),   
    CONSTRAINT fk_localizacao_dept FOREIGN KEY (numero_dept) REFERENCES departamento(numero_dept)
);


CREATE TABLE funcionario (
    matricula_func INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    sexo CHAR(1) NOT NULL,
    salario DECIMAL(10, 2) NOT NULL,
    data_nascimento DATE NOT NULL,
    numero_dept INT,
    matricula_supervisor INT,

    PRIMARY KEY(matricula_func),
    CONSTRAINT fk_funcionario_dept FOREIGN KEY (numero_dept) REFERENCES departamento(numero_dept),
    CONSTRAINT fk_funcionario_supervisor FOREIGN KEY (matricula_supervisor) REFERENCES funcionario(matricula_func)
);

CREATE TABLE dependente (
    id_dependente INT NOT NULL, -- não é AUTO_INCREMENT porque a chave primária é composta
    matricula_func INT NOT NULL,
    nome VARCHAR(50) NOT NULL,
    sexo CHAR(1) NOT NULL,
    data_nascimento DATE NOT NULL,

    PRIMARY KEY (matricula_func, id_dependente),
    CONSTRAINT fk_dependente_funcionario FOREIGN KEY (matricula_func) REFERENCES funcionario(matricula_func)
);





