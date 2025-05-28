# 🕹️ Pac-Fantasma

Um jogo simples em C inspirado no clássico Pac-Man, onde o jogador deve sobreviver e escapar de fantasmas enquanto coleta pílulas para liberar um ataque especial!

---

## 📜 Descrição

Você controla um personagem que se move por um labirinto. Espalhados pelo mapa estão fantasmas e uma pílula especial. Ao coletar a pílula, o jogador pode ativar um poder de explosão que limpa o caminho e elimina inimigos próximos.

---

## 🎮 Regras do Jogo

- Use as teclas **W, A, S, D** para mover o personagem.
- Pegue a **pílula** para ativar o **poder especial**.
- Pressione **B** para usar a explosão (se tiver uma pílula).
- O jogo termina quando:
  - Você é pego por um fantasma (**derrota**), ou
  - Todos os fantasmas são eliminados (**vitória**).

---

## 🧩 Controles

| Tecla | Ação                 |
|-------|----------------------|
| `W`   | Mover para cima      |
| `A`   | Mover para esquerda  |
| `S`   | Mover para baixo     |
| `D`   | Mover para direita   |
| `B`   | Usar explosão (pílula)|

---

## 🛠️ Compilação e Execução

1. Compile os arquivos do projeto com o `gcc`:

```bash
gcc main.c mapa.c interface.c jogo.c -o jogo
```

2. Execute o jogo:

```bash
./jogo
```

> Certifique-se de que os arquivos `jogo.h`, `mapa.h`, `interface.h` e os arquivos `.c` correspondentes estejam na mesma pasta.

---

## 📂 Estrutura dos Arquivos

- `main.c` — Lógica principal do jogo
- `jogo.c/.h` — Funções de movimentação e ações do personagem
- `mapa.c/.h` — Manipulação do mapa e posições
- `interface.c/.h` — Interface com o usuário (impressão do mapa, etc)

---

## ✅ Estado do Projeto

- [x] Movimentação de personagem
- [x] IA simples para fantasmas
- [x] Sistema de pílula especial
- [x] Leitura de mapa
- [ ] Interface gráfica (modo texto apenas)

---

## 📄 Certificado 
![image](https://github.com/user-attachments/assets/f7b1e7df-807a-48e7-bcc5-4d2dce76b4eb)


