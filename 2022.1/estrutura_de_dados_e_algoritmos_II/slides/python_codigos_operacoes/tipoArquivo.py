from dataclasses import dataclass
import this

MTAMARQUIVO = 10
MTAMNOME = 20

@dataclass
class DadosUsuario:
    chave: int
    nome: str
    def __init__(self) -> None:
        pass
    
    def insert_chave(chave):
        this.chave = chave

    def insert_nome(nome):
        this.nome = nome


@dataclass
class Registro:
    ocupado: bool
    dados: DadosUsuario
    def __init__(self) -> None:
        pass

    def insert_ocupado(ocupado):
        this.ocupado = ocupado
    
    def insert_dados(dados):
        this.dados = dados
