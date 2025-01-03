# Readme - Sistema de Gerenciamento de Farmácia

Este é um código-fonte em linguagem C para um sistema simples de gerenciamento de farmácia. O programa permite a inclusão, exclusão, alteração, consulta e listagem de medicamentos em um arquivo de dados.

## Descrição

O programa utiliza uma estrutura de dados para representar informações sobre medicamentos, incluindo nome, preço e quantidade em estoque. Ele oferece as seguintes funcionalidades:

1. **Incluir**: Permite adicionar um novo medicamento ao arquivo de dados, desde que o medicamento ainda não exista no arquivo.

2. **Excluir**: Permite marcar um medicamento como excluído, alterando a quantidade em estoque para -1. Isso não remove fisicamente o registro do arquivo, mas o marca como excluído.

3. **Alterar**: Permite modificar o preço e a quantidade em estoque de um medicamento existente no arquivo.

4. **Consultar**: Permite consultar informações de um medicamento específico, desde que ele não tenha sido excluído.

5. **Listar Todos**: Exibe uma lista de todos os medicamentos que não foram marcados como excluídos.

O programa usa um arquivo binário para armazenar os dados dos medicamentos. Cada medicamento é representado por uma estrutura de dados e é identificado pelo seu nome.

## Como Usar

1. Compile o código-fonte em C para criar um executável.

2. Execute o programa. Ele oferecerá um menu com opções para as funcionalidades mencionadas.

3. Siga as instruções do programa para realizar as operações desejadas, como inclusão, exclusão, alteração, consulta e listagem de medicamentos.

4. O programa usará um arquivo chamado "Farmacos.dat" para armazenar os dados dos medicamentos. Certifique-se de que este arquivo esteja no mesmo diretório do executável.

## Pré-requisitos

Para compilar e executar o programa, você precisa de um compilador C compatível com seu sistema operacional.

## Autor

- **Autor:** Guilherme Franco 

## Motivações

Este programa, denominado "Pague Pouco", foi desenvolvido como parte da prova de terceira unidade do curso de Programação Imperativa na Universidade Federal de Sergipe, no período letivo de 2022.2. A prova consistia em implementar funcionalidades específicas em um sistema de gerenciamento de farmácia, conhecido como "Pague Pouco", que utiliza um arquivo binário para armazenar informações sobre medicamentos.

As instruções fornecidas na prova eram as seguintes:

a) Ajustar o "Incluir" de forma a impossibilitar a adição de medicamentos com nomes idênticos.
   
b) Ajustar o "Incluir" de forma a não exibir os medicamentos excluídos.

c) Ajustar o "LTodos" de forma a não exibir os medicamentos excluídos.

d) Ajustar o "Consultar" de forma a não exibir os medicamentos excluídos.

e) Tornar o procedimento de alteração mais amigável para o usuário.

f) Implementar a exclusão lógica, para tanto, usar o campo "QEstoque" atribuindo -1 a esse campo.

O programa foi desenvolvido para atender a esses requisitos, garantindo que medicamentos com nomes idênticos não pudessem ser adicionados, ocultando medicamentos excluídos nas operações de inclusão, consulta e listagem, tornando a alteração mais amigável ao usuário e implementando a exclusão lógica por meio da atribuição de -1 ao campo "QEstoque".

O objetivo da prova era avaliar a capacidade dos alunos de aplicar os conceitos de programação em C, manipulação de arquivos e estruturas de dados em um contexto prático. A conclusão bem-sucedida deste projeto demonstra a compreensão e a aplicação dos conceitos ensinados no curso de Programação Imperativa na Universidade Federal de Sergipe.


---
