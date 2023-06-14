CREATE TABLE `Aluno`
(
 `cpf`             varchar(11) NOT NULL ,
 `curso`           varchar(100) NOT NULL ,
 `nome`            varchar(200) NOT NULL ,
 `rg`              varchar(20) NOT NULL ,
 `numeroMatricula` varchar(45) NOT NULL ,
 `periodo`         smallint NOT NULL ,

PRIMARY KEY (`cpf`)
);





CREATE TABLE `InstituicaoContratante`
(
 `cnpj`            varchar(22) NOT NULL ,
 `razaoSocial`     varchar(200) NOT NULL ,
 `nomeFantasia`    varchar(100) NOT NULL ,
 `nomeResponsavel` varchar(100) NOT NULL ,
 `site`            varchar(100) ,
 `endereco`        varchar(200) ,
 `areaAtuacao`     varchar(100) NOT NULL ,

PRIMARY KEY (`cnpj`)
);




CREATE TABLE `VagaEstagio`
(
 `idVaga`              int NOT NULL ,
 `titulo`              varchar(100) NOT NULL ,
 `requisitos`          varchar(200) NOT NULL ,
 `descricaoAtividades` varchar(400) NOT NULL ,
 `beneficios`          varchar(100) ,
 `remuneracao`         decimal(5,2) ,
 `cargaHoraria`        smallint NOT NULL ,
 `localizacao`         varchar(100) ,
 `modalidade`          char NOT NULL ,
 `prazo`               date ,
 `finalizado`          binary NOT NULL ,
 `cnpj`                varchar(22) NOT NULL ,

PRIMARY KEY (`idVaga`),
KEY `FK_1` (`cnpj`),
CONSTRAINT `FK_1` FOREIGN KEY `FK_1` (`cnpj`) REFERENCES `InstituicaoContratante` (`cnpj`)
);




CREATE TABLE `seCandidataEm`
(
 `idVaga`    int NOT NULL ,
 `cpf_1`     varchar(11) NOT NULL ,
 `curriculo` varchar(45) NOT NULL ,

PRIMARY KEY (`idVaga`, `cpf_1`),
KEY `FK_1` (`cpf_1`),
CONSTRAINT `FK_2` FOREIGN KEY `FK_1` (`cpf_1`) REFERENCES `Aluno` (`cpf`),
KEY `FK_2` (`idVaga`),
CONSTRAINT `FK_3` FOREIGN KEY `FK_2` (`idVaga`) REFERENCES `VagaEstagio` (`idVaga`)
);





