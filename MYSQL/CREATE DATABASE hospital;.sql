CREATE DATABASE hospital;

USE hospital;

-- DROP TABLE IF EXISTS pacientes;
-- DROP TABLE IF EXISTS especialidade;
-- DROP TABLE IF EXISTS medicos;
-- DROP TABLE IF EXISTS consultas;
-- DROP TABLE IF EXISTS receitas;
-- DROP TABLE IF EXISTS medicamento;
-- DROP TABLE IF EXISTS tipos_exames;
-- DROP TABLE IF EXISTS exames;

CREATE TABLE pacientes (
    id_paciente INT AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(11) NOT NULL UNIQUE,
    data_cadastro DATE NOT NULL,
    observacao VARCHAR(255),

    PRIMARY KEY (id_paciente)
);

CREATE TABLE especialidade (
    id_especialidade INT,
    tipo VARCHAR(50) NOT NULL,

    PRIMARY KEY (id_especialidade)
);

CREATE TABLE medicos (
    crm VARCHAR(11) NOT NULL,
    nome VARCHAR(100) NOT NULL,
    especialidade INT NOT NULL,

    PRIMARY KEY (crm),
    CONSTRAINT fk_especialidade FOREIGN KEY (especialidade) REFERENCES especialidade(id_especialidade)

);


CREATE TABLE consultas (
    id_consulta INT AUTO_INCREMENT,
    id_paciente INT NOT NULL,
    crm_medico VARCHAR(11) NOT NULL,
    data_consulta DATE NOT NULL,
    diagnostico VARCHAR(255),
    observacao VARCHAR(255),

    PRIMARY KEY (id_consulta),

    CONSTRAINT fk_paciente FOREIGN KEY (id_paciente) REFERENCES pacientes(id_paciente),
    CONSTRAINT fk_medico FOREIGN KEY (crm_medico) REFERENCES medicos(crm)

);


CREATE TABLE receitas (
    id_receita INT AUTO_INCREMENT,
    id_consulta INT NOT NULL,
    observacao VARCHAR(255),

    PRIMARY KEY (id_receita),
    CONSTRAINT fk_consulta_receita FOREIGN KEY (id_consulta) REFERENCES consultas(id_consulta)
);


CREATE TABLE medicamento (
    id_medicamento INT AUTO_INCREMENT,
    id_receita INT NOT NULL,
    nome_medicamento VARCHAR(100) NOT NULL,
    dosagem VARCHAR(50) NOT NULL,
    frequencia VARCHAR(50) NOT NULL,
    preco DECIMAL(10, 2) NOT NULL,

    PRIMARY KEY (id_medicamento),
    CONSTRAINT fk_medicamento_receita FOREIGN KEY (id_receita) REFERENCES receitas(id_receita)
);


CREATE TABLE tipos_exames (
    id_tipo_exame INT AUTO_INCREMENT,
    nome_exame VARCHAR(100) NOT NULL,
    descricao VARCHAR(255),
    preco DECIMAL(10, 2) NOT NULL,

    PRIMARY KEY (id_tipo_exame)
);

CREATE TABLE exames (
    id_exame INT AUTO_INCREMENT,
    id_consulta INT NOT NULL,
    id_tipo_exame INT NOT NULL,
    observacao VARCHAR(255),
    diagnostico VARCHAR(255),

    PRIMARY KEY (id_exame)
    CONSTRAINT fk_consulta FOREIGN KEY (id_consulta) REFERENCES consultas(id_consulta),
    CONSTRAINT fk_tipo_exame FOREIGN KEY (id_tipo_exame) REFERENCES tipos_exames(id_tipo_exame)
);






