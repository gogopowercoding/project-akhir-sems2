import tkinter as tk
from python.tambahLagu import TambahLagu 
import cpp

root = tk.Tk()


buttons = [
        {"title": "Input Lagu", "action": lambda: TambahLagu(root, cpp.tambah_lagu)},
        {"title": "Cari Lagu by Judul (sequential)", "action": lambda : None},
        {"title": "Cari Lagu by Judul (binary)", "action": lambda : None},
        {"title": "Cari Lagu by Lirik", "action": lambda : None},
        {"title": "Chart Lagu", "action": lambda : None},

        ]


row = 1
for b in buttons:
    button = tk.Button(root, text=b["title"], command=b["action"])
    button.grid(row=row-1, column=0, padx=10, pady=10)
    row += 1


root.mainloop()
