

# 🦖 Dino Runner Game in C

A fun, console-based Dino Runner game written in C — inspired by the Chrome offline dino game. Run, jump, and dodge obstacles right in your terminal.

---

## 🧠 Game Overview

Your dino (🦖) runs on the ground. Obstacles appear from the right, and your job is to **jump** over them by pressing the **Spacebar**. The longer you survive, the faster the game gets!

---

## 🖥️ Platform Compatibility

✅ macOS
✅ Linux
❌ Windows (for Windows, see [Windows version](#))

---

## 🚀 Getting Started on macOS/Linux

### 🔧 Prerequisites

Make sure you have a C compiler installed:

```bash
xcode-select --install   # For macOS
sudo apt install build-essential   # For Ubuntu/Debian
```

---

### 📂 File Structure

```
.
├── dino.c           # Main game source code
├── README.md        # This file
```

---

### ⚙️ Compile the Game

In your terminal, navigate to the directory and run:

```bash
gcc -o dino dino.c
```

> If you're on macOS, `clang` also works:

```bash
clang -o dino dino.c
```

---

### ▶️ Run the Game

```bash
./dino
```

---

## 🎮 Controls

| Key      | Action             |
| -------- | ------------------ |
| Spacebar | Jump               |
| X or x   | Exit/Quit the game |

---

## 🧱 Features

* Dynamic obstacle generation.
* Jump animation with ASCII art.
* Increasing game speed as score increases.
* Score display.
* Game Over detection with collision check.
* Works without any graphics library — only terminal control.

---

## 🔄 Known Limitations on macOS/Linux

| Limitation                        | Notes                                                             |
| --------------------------------- | ----------------------------------------------------------------- |
| No sound                          | Uses no sound APIs                                                |
| Terminal size                     | Tries to resize using escape codes, may not work in all terminals |
| Best in iTerm2 or modern Terminal |                                                                   |
| No color                          | Currently monochrome; can be extended                             |

---

## 🧩 How It Works

* Uses `moveTo()` with ANSI escape codes (`\033[x;yH`) to control cursor.
* Game loop runs real-time using `clock()` for animation timing.
* `getchar()` and `kbhit()` are simulated using Unix termios settings for non-blocking key detection.

---

## ✅ Customization Tips

* Adjust obstacle speed: modify `gameSpeed`.
* Add more obstacle types or animations.
* Add a scoreboard or high score save.

---

## 🧑‍💻 Author

Made by **Ekaagra gupta**
Built using **C**, compatible with **macOS Terminal/iTerm2**.

---

## 📜 License

This game is released as open-source for educational and recreational use. No dinosaurs were harmed during development 🦕.

