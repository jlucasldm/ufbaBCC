import pandas as pd 
import seaborn as srn

df=pd.read_csv('equipe_sample__Salvador.csv', sep=";")
pd.set_option("display.max_rows", None, "display.max_columns", None)
df.columns = ["insc", "ano", "coMunicp", "municp", "coUf", "uf", "idade", "sexo", "estdCivil", "cor", "nacionalidade", 
              "coMunicpNasc", "municpNasc", "coUfNasc", "ufNasc", "conclEnsMed", "anoConclEnsMed", "escolEnsMed", "tipEscolEnsMed", 
              "treineiro", "coEscol", "coMunicpEscol", "municpEscol", "coUfEscol", "ufEscol", "dependEcol", "localEscol", "situEscol", "IN_BAIXA_VISAO", "IN_CEGUEIRA", "IN_SURDEZ", "IN_DEFICIENCIA_AUDITIVA", "IN_SURDO_CEGUEIRA", "IN_DEFICIENCIA_FISICA", "IN_DEFICIENCIA_MENTAL", "IN_DEFICIT_ATENCAO", "IN_DISLEXIA", "IN_DISCALCULIA", "IN_AUTISMO", "IN_VISAO_MONOCULAR", "IN_OUTRA_DEF", "IN_GESTANTE", "IN_LACTANTE", "IN_IDOSO", "IN_ESTUDA_CLASSE_HOSPITALAR", "IN_SEM_RECURSO", "IN_BRAILLE", "IN_AMPLIADA_24", "IN_AMPLIADA_18", "IN_LEDOR", "IN_ACESSO", "IN_TRANSCRICAO", "IN_LIBRAS", "IN_TEMPO_ADICIONAL", "IN_LEITURA_LABIAL", "IN_MESA_CADEIRA_RODAS", "IN_MESA_CADEIRA_SEPARADA", "IN_APOIO_PERNA", "IN_GUIA_INTERPRETE", "IN_COMPUTADOR", "IN_CADEIRA_ESPECIAL", "IN_CADEIRA_CANHOTO", "IN_CADEIRA_ACOLCHOADA", "IN_PROVA_DEITADO", "IN_MOBILIARIO_OBESO", "IN_LAMINA_OVERLAY", "IN_PROTETOR_AURICULAR", "IN_MEDIDOR_GLICOSE", "IN_MAQUINA_BRAILE", "IN_SOROBAN", "IN_MARCA_PASSO", "IN_SONDA", "IN_MEDICAMENTOS", "IN_SALA_INDIVIDUAL", "IN_SALA_ESPECIAL", "IN_SALA_ACOMPANHANTE", "IN_MOBILIARIO_ESPECIFICO", "IN_MATERIAL_ESPECIFICO", "IN_NOME_SOCIAL", 
              "coMunicpProva", "municpProva", "coUfProva", "ufProva", "presCN", "presCH", "presLC", "presMT", "coProvaCN", "coProvaCH", 
              "coProvaLC", "coProvaMT", "notaCN", "notaCH", "notaLC", "notaMT", "respCN", "respCH", "respLC", "respMT", "tipoLing", "gabaritoCN", 
              "gabaritoCH", "gabaritoLC", "gabaritoMT", "situRedac", "notaComp1", "notaComp2", "notaComp3", "notaComp4", "notaComp5", "notaRedacao", 
              "QSituEscolPai", "QSituEscolMae", "QTrablPai", "QTrablMae", "QQtdPesResid", "QRendaFamil", "QTemEmpgDomest", "QQtdBanheiro", 
              "QQtdQuartos", "QQtdCarro", "QQtdMotoCicl", "QQtdGeladeira", "QQtdFreezer", "QQtdMaqLavarRoupa", "QQtdMaqSecarRoupa", 
              "QQtdMicroondas", "QQtdMaqLavarLouca", "QTemAspiradorPo", "QQtdTv", "QTemDvd", "QTemTvAssin", "QQtdCelular", "QTemTelFixo", 
              "QQtdComptd", "QTemInternet"]

df['idade'].describe()
agrupado = df.groupby(['sexo']).size()

df['notaCN'] = df['notaCN'].apply(lambda x: float(x.replace(',', '.')))
df['notaCH'] = df['notaCH'].apply(lambda x: float(x.replace(',', '.')))
df['notaLC'] = df['notaLC'].apply(lambda x: float(x.replace(',', '.')))
df['notaMT'] = df['notaMT'].apply(lambda x: float(x.replace(',', '.')))

faixa_de_renda = ['Nenhuma renda.','Até R$ 998,00',
        'De R$ 998,01 até R$ 1.497,00','De R$ 1.497,01 até R$ 1.996,00',
        'De R$ 1.996,01 até R$ 2.495,00','De R$ 2.495,01 até R$ 2.994,00',
        'De R$ 2.994,01 até R$ 3.992,00','De R$ 3.992,01 até R$ 4.990,00',
        'De R$ 4.990,01 até R$ 5.988,00','De R$ 5.988,01 até R$ 6.986,00',
        'De R$ 6.986,01 até R$ 7.984,00','De R$ 7.984,01 até R$ 8.982,00',
        'De R$ 8.982,01 até R$ 9.980,00','De R$ 9.980,01 até R$ 11.976,00',
        'De R$ 11.976,01 até R$ 14.970,00','De R$ 14.970,01 até R$ 19.960,00',
        'Mais de R$ 19.960,00']
sexo = ['Maculino', 'Feminino']
areas_de_notas = ['notaCN','notaCH','notaLC','notaMT']
medias = []
raca = ['Preta','Parda','Amarela','Branca','Não Declarado']

for i_sexo in sexo:
    print(i_sexo)
    print('Faixa de renda \t\t\t\tNota CN\tNota CH\tNota LC\tNota Mt')

    for i_faixa in faixa_de_renda:
        if len(i_faixa) < 15:
            espacamento = '\t\t\t\t'
        elif len(i_faixa) >= 15 and len(i_faixa) <= 20:
            espacamento = '\t\t\t'
        elif len(i_faixa) > 20 and len(i_faixa) < 32:
            espacamento = '\t\t'
        elif len(i_faixa) >= 32:
            espacamento = '\t'
        
        for i_notas in areas_de_notas:
            medias.append(str(df.loc[(df['QRendaFamil'] == i_faixa) & (df['sexo'] == i_sexo),[i_notas]].median(axis=0))[10:16].replace('\n',''))
            #print(medias)
        
        string = str(i_faixa) + str(espacamento) + str(medias[0]) + '\t' + str(medias[1]) + '\t' + str(medias[2]) + '\t' + str(medias[3])
        print(string)
        medias = []
    print()

# print('Até R$ 998,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'Até R$ 998,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('Até R$ 998,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'Até R$ 998,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 1.497,01 até R$ 1.996,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 1.497,01 até R$ 1.996,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 1.497,01 até R$ 1.996,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 1.497,01 até R$ 1.996,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 1.996,01 até R$ 2.495,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 1.996,01 até R$ 2.495,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 1.996,01 até R$ 2.495,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 1.996,01 até R$ 2.495,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 11.976,01 até R$ 14.970,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 11.976,01 até R$ 14.970,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 11.976,01 até R$ 14.970,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 11.976,01 até R$ 14.970,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 14.970,01 até R$ 19.960,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 14.970,01 até R$ 19.960,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 14.970,01 até R$ 19.960,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 14.970,01 até R$ 19.960,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 2.495,01 até R$ 2.994,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 2.495,01 até R$ 2.994,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 2.495,01 até R$ 2.994,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 2.495,01 até R$ 2.994,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 2.994,01 até R$ 3.992,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 2.994,01 até R$ 3.992,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 2.994,01 até R$ 3.992,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 2.994,01 até R$ 3.992,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 3.992,01 até R$ 4.990,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 3.992,01 até R$ 4.990,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 3.992,01 até R$ 4.990,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 3.992,01 até R$ 4.990,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 4.990,01 até R$ 5.988,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 4.990,01 até R$ 5.988,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 4.990,01 até R$ 5.988,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 4.990,01 até R$ 5.988,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 5.988,01 até R$ 6.986,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 5.988,01 até R$ 6.986,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 5.988,01 até R$ 6.986,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 5.988,01 até R$ 6.986,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 6.986,01 até R$ 7.984,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 6.986,01 até R$ 7.984,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 6.986,01 até R$ 7.984,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 6.986,01 até R$ 7.984,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 7.984,01 até R$ 8.982,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 7.984,01 até R$ 8.982,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 7.984,01 até R$ 8.982,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 7.984,01 até R$ 8.982,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 8.982,01 até R$ 9.980,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 8.982,01 até R$ 9.980,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 8.982,01 até R$ 9.980,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 8.982,01 até R$ 9.980,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 9.980,01 até R$ 11.976,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 9.980,01 até R$ 11.976,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 9.980,01 até R$ 11.976,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 9.980,01 até R$ 11.976,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 998,01 até R$ 1.497,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 998,01 até R$ 1.497,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('De R$ 998,01 até R$ 1.497,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'De R$ 998,01 até R$ 1.497,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('Mais de R$ 19.960,00 Feminino')
# print(df.loc[(df['QRendaFamil'] == 'Mais de R$ 19.960,00') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('Mais de R$ 19.960,00 Masculino')
# print(df.loc[(df['QRendaFamil'] == 'Mais de R$ 19.960,00') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('Nenhuma renda. Feminino')
# print(df.loc[(df['QRendaFamil'] == 'Nenhuma renda.') & (df['sexo'] == 'Feminino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
# print('Nenhuma renda. Masculino')
# print(df.loc[(df['QRendaFamil'] == 'Nenhuma renda.') & (df['sexo'] == 'Maculino'),['notaCN','notaCH','notaLC','notaMT']].median(axis=0))
