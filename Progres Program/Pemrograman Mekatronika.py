import tkinter as tk
from tkinter import ttk
from tkinter.messagebox import showinfo

window = tk.Tk()

window.configure(bg="white")
window.geometry("1366x768")
window.title("GUI ROBOT CARTESIAN!")

# frame input
input_frame = ttk.Frame(window)
# penempatan Grid, pack, place
input_frame.pack(padx=10,pady=10,fill='x',expand=True)

#Komponen-komponen
#1.Label nama depan
nama_depan_label = ttk.Label(input_frame,text="Koordinat X")
nama_depan_label.pack(padx=10,pady=10,fill='x',expand=True)
#2.Entry nama depan
NAMA_DEPAN = tk.StringVar()
nama_depan_entry = ttk.Entry(input_frame,textvariable=NAMA_DEPAN)
nama_depan_entry.pack(padx=10,pady=10,fill='x',expand=True)
#3.Label nama Belakang
nama_Belakang_label = ttk.Label(input_frame,text="Koordinat Y")
nama_Belakang_label.pack(padx=10,pady=10,fill='x',expand=True)
#4.Entry nama Belakang
NAMA_BELAKANG = tk.StringVar()
nama_Belakang_entry = ttk.Entry(input_frame,textvariable=NAMA_BELAKANG)
nama_Belakang_entry.pack(padx=10,pady=10,fill='x',expand=True)
#5.Label nama atas
nama_atas_label = ttk.Label(input_frame,text="Koordinat Z")
nama_atas_label.pack(padx=10,pady=10,fill='x',expand=True)
#6.Entry nama atas
NAMA_ATAS = tk.StringVar()
nama_atas_entry = ttk.Entry(input_frame,textvariable=NAMA_ATAS)
nama_atas_entry.pack(padx=10,pady=10,fill='x',expand=True)
#7.Tombol
def tombol_click():
    print(NAMA_DEPAN,NAMA_BELAKANG,NAMA_ATAS.get())
    pesan = "Running Complete"
    showinfo(title="wahtsapp!",message=pesan)
tombol_run = tk.Button(input_frame,text="RUN!",command=tombol_click)
tombol_run.pack(padx=10,pady=10,fill='x',expand=True)






window.mainloop()