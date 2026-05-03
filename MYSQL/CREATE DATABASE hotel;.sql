USE hotel;


-- 2. Criando as tabelas com a sintaxe correta e os espaços nos comentários
CREATE TABLE hospedes (
    id_hospede int AUTO_INCREMENT PRIMARY KEY,
    nome varchar(255) NOT NULL,
    cpf varchar(11) NOT NULL UNIQUE,
    observacao varchar(255),
    data_cadastro datetime DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE numero_telefones (
    id_hospede INT NOT NULL,
    numero_telefone VARCHAR(15) NOT NULL,
    PRIMARY KEY (id_hospede, numero_telefone),
    CONSTRAINT fk_numero_telefones FOREIGN KEY (id_hospede) REFERENCES hospedes(id_hospede)
);

CREATE TABLE endereco_hospede (
    id_hospede INT NOT NULL,
    endereco VARCHAR(255) NOT NULL,
    PRIMARY KEY (id_hospede, endereco),
    CONSTRAINT fk_endereco_hospede FOREIGN KEY (id_hospede) REFERENCES hospedes(id_hospede)
);

CREATE TABLE email_hospede (
    id_hospede INT NOT NULL,
    email VARCHAR(100) NOT NULL,
    PRIMARY KEY (id_hospede, email),
    CONSTRAINT fk_email_hospede FOREIGN KEY (id_hospede) REFERENCES hospedes(id_hospede)
);

CREATE TABLE tipo_quarto (
    id_tipo_quarto int auto_increment PRIMARY KEY,
    descricao varchar(255) NOT NULL, 
    preco decimal(10,2) NOT NULL
);

CREATE TABLE QUARTOS (
    id_quarto int auto_increment PRIMARY KEY,
    qtde_hospedes int NOT NULL,
    id_tipo_quarto int NOT NULL,
    CONSTRAINT fk_tipo_quarto FOREIGN KEY (id_tipo_quarto) REFERENCES tipo_quarto(id_tipo_quarto)
);

CREATE TABLE reservas (
    id_reserva int auto_increment PRIMARY KEY,
    id_hospede int NOT NULL,
    id_quarto int NOT NULL,
    data_reserva datetime NOT NULL,
    CONSTRAINT fk_reserva_hospede FOREIGN KEY (id_hospede) REFERENCES hospedes(id_hospede),
    CONSTRAINT fk_reserva_quarto FOREIGN KEY (id_quarto) REFERENCES QUARTOS(id_quarto)
);