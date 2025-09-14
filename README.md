# 📄 get_next_line

Projeto da 42 São Paulo cujo objetivo é implementar uma função chamada `get_next_line`, que retorna uma linha de um *file descriptor* por chamada, mantendo o estado entre chamadas sucessivas. 
Esta versão inclui os recursos obrigatórios e bônus.

## 🧠 Objetivo

Implementar a função:

```c
char *get_next_line(int fd)
```
Ela deve ler uma linha por vez de um arquivo (ou qualquer file descriptor válido), até encontrar um \n ou EOF, mantendo o que sobrou em buffer para a próxima chamada.

## ✅ Regras

A função deve funcionar com múltiplos FDs abertos ao mesmo tempo (No caso do bonus). 
A leitura é feita com um BUFFER_SIZE definido no momento da compilação.
Deve funcionar para qualquer tipo de arquivo legível.

## 🛠️ Compilação

Compile usando um dos comandos abaixo:
Para o obrigatorio: 
```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
Para o Bonus:
```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```
Obs: Substitua 42 pelo valor de BUFFER_SIZE que desejar.
