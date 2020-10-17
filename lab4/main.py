import tkinter as tk
from view import view


class RootWindow(tk.Tk):
    """
        Representation of root program window.
    """

    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)

        img = tk.PhotoImage(file="assets/img/icon.png")

        self.geometry("1400x750+0+0")
        self.minsize(1, 1)
        self.maxsize(1920, 1010)
        self.resizable(0, 0)
        self.title("Circle drawing")
        self.iconphoto(True, img)
        self.configure(
            highlightcolor="black"
        )

        self.image = tk.Canvas(self)
        self.image.place(relx=0.4, rely=0.028, relheight=0.945, relwidth=0.58)
        self.image.configure(
            background="#ffffff",
            borderwidth="2",
            relief="ridge",
            selectbackground="#c4c4c4"
        )

        # Shape selection section.
        self.shapelb = tk.Label(self)
        self.shapelb.place(relx=0.039, rely=0.002, height=30, width=477)
        self.shapelb.configure(
            activebackground="white",
            activeforeground="white",
            font="-family {Consolas} -size 18",
            foreground="black",
            text="ФИГУРА"
        )

        self.shapelst = tk.Listbox(self, exportselection=0)
        self.shapelst.place(relx=0.039, rely=0.05, relheight=0.08, relwidth=0.342)
        self.shapelst.configure(
            background="white",
            foreground="black",
            selectbackground="#000080",
            selectforeground="white",
            font="-family {Consolas} -size 14"
        )
        self.shapelst.insert(tk.END, "Окружность")
        self.shapelst.insert(tk.END, "Эллипс")
        self.shapelst.bind("<Button-1>", lambda event,
                           listbox=self.shapelst: view.check_lb(event, ROOT))

        # Drawing method section.
        self.methodlb = tk.Label(self)
        self.methodlb.place(relx=0.037, rely=0.135, height=30, width=477)
        self.methodlb.configure(
            activebackground="white",
            activeforeground="white",
            font="-family {Consolas} -size 18",
            foreground="black",
            text="МЕТОД ПОСТРОЕНИЯ"
        )

        self.methodlst = tk.Listbox(self, exportselection=0)
        self.methodlst.place(relx=0.037, rely=0.175, relheight=0.1, relwidth=0.342)
        self.methodlst.configure(
            background="white",
            foreground="black",
            selectbackground="#000080",
            selectforeground="white",
            font="-family {Consolas} -size 14"
        )
        self.methodlst.insert(tk.END, "Каноническое уравнение")
        self.methodlst.insert(tk.END, "Параметрическое уравнение")
        self.methodlst.insert(tk.END, "Алгоритм Брезенхема")
        self.methodlst.insert(tk.END, "Алгоритм средней точки")
        self.methodlst.insert(tk.END, "Библиотечная функция")
        self.methodlst.bind("<Button-1>", lambda event,
                            listbox=self.methodlst: view.check_lb(event, ROOT))

        # Drawing color section.
        self.colorlb = tk.Label(self)
        self.colorlb.place(relx=0.037, rely=0.28, height=30, width=477)
        self.colorlb.configure(
            activebackground="white",
            activeforeground="white",
            font="-family {Consolas} -size 18",
            foreground="black",
            text="ЦВЕТ ПОСТРОЕНИЯ"
        )

        self.colorlst = tk.Listbox(self, exportselection=0)
        self.colorlst.place(relx=0.037, rely=0.32, relheight=0.07, relwidth=0.342)
        self.colorlst.configure(
            background="white",
            foreground="black",
            selectbackground="#000080",
            selectforeground="white",
            font="-family {Consolas} -size 14"
        )
        self.colorlst.insert(tk.END, "Синий")
        self.colorlst.insert(tk.END, "Фоновый")
        self.colorlst.bind("<Button-1>", lambda event,
                           listbox=self.colorlst: view.check_lb(event, ROOT))

        # Shape parameters section.
        self.shapeparlb = tk.Label(self)
        self.shapeparlb.place(relx=0.037, rely=0.4, height=30, width=477)
        self.shapeparlb.configure(
            activebackground="white",
            activeforeground="white",
            font="-family {Consolas} -size 18",
            foreground="black",
            text="ПАРАМЕТРЫ ФИГУРЫ"
        )

        self.xcenterlb = tk.Label(self)
        self.xcenterlb.place(relx=0.037, rely=0.444, height=28, width=85)
        self.xcenterlb.configure(
            activebackground="#f9f9f9",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="Xc"
        )

        self.ycenterlb = tk.Label(self)
        self.ycenterlb.place(relx=0.1, rely=0.444, height=28, width=85)
        self.ycenterlb.configure(
            font="-family {Consolas} -size 14",
            foreground="black",
            text="Yc"
        )

        self.r1lb = tk.Label(self)
        self.r1lb.place(relx=0.163, rely=0.444, height=28, width=85)
        self.r1lb.configure(
            activebackground="#f9f9f9",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="R1"
        )

        self.r2lb = tk.Label(self)
        self.r2lb.place(relx=0.226, rely=0.444, height=28, width=85)
        self.r2lb.configure(
            activebackground="#f9f9f9",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="R2"
        )

        self.xcentersb = tk.Spinbox(self)
        self.xcentersb.place(relx=0.037, rely=0.485, relheight=0.03, relwidth=0.063)
        self.xcentersb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=1300.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.ycentersb = tk.Spinbox(self)
        self.ycentersb.place(relx=0.1, rely=0.485, relheight=0.03, relwidth=0.063)
        self.ycentersb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=955.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.r1sb = tk.Spinbox(self)
        self.r1sb.place(relx=0.162, rely=0.485, relheight=0.03, relwidth=0.063)
        self.r1sb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=487.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.r2sb = tk.Spinbox(self)
        self.r2sb.place(relx=0.224, rely=0.485, relheight=0.03, relwidth=0.063)
        self.r2sb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=487.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.drawbtn = tk.Button(self)
        self.drawbtn.place(relx=0.037, rely=0.522, height=40, width=477)
        self.drawbtn.configure(
            background="#d9d9d9",
            foreground="black",
            activebackground="white",
            font="-family {Consolas} -size 14",
            text="Построить фигуру",
            state="disabled",
            command=lambda: view.draw(ROOT)
        )

        # Spectre drawing section.
        self.spectrelb = tk.Label(self)
        self.spectrelb.place(relx=0.037, rely=0.578, height=30, width=477)
        self.spectrelb.configure(
            activebackground="white",
            activeforeground="white",
            font="-family {Consolas} -size 18",
            foreground="black",
            text="ПАРАМЕТРЫ СПЕКТРА"
        )

        self.xscenterlb = tk.Label(self)
        self.xscenterlb.place(relx=0.037, rely=0.62, height=28, width=175)
        self.xscenterlb.configure(
            activebackground="white",
            activeforeground="white",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="Xc"
        )

        self.yscenterlb = tk.Label(self)
        self.yscenterlb.place(relx=0.163, rely=0.62, height=28, width=175)
        self.yscenterlb.configure(
            activebackground="white",
            activeforeground="white",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="Yc"
        )

        self.xscentersb = tk.Spinbox(self)
        self.xscentersb.place(relx=0.037, rely=0.664, relheight=0.033, relwidth=0.127)
        self.xscentersb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=1300.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.yscentersb = tk.Spinbox(self)
        self.yscentersb.place(relx=0.163, rely=0.664, relheight=0.033, relwidth=0.127)
        self.yscentersb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=955.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.rs1lb = tk.Label(self)
        self.rs1lb.place(relx=0.037, rely=0.705, height=34, width=80)
        self.rs1lb.configure(
            activebackground="#f9f9f9",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="R1"
        )

        self.rs2lb = tk.Label(self)
        self.rs2lb.place(relx=0.1, rely=0.705, height=34, width=80)
        self.rs2lb.configure(
            activebackground="#f9f9f9",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="R2"
        )

        self.steplb = tk.Label(self)
        self.steplb.place(relx=0.163, rely=0.705, height=34, width=80)
        self.steplb.configure(
            activebackground="#f9f9f9",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="Шаг"
        )

        self.nlb = tk.Label(self)
        self.nlb.place(relx=0.226, rely=0.705, height=34, width=80)
        self.nlb.configure(
            activebackground="#f9f9f9",
            font="-family {Consolas} -size 14",
            foreground="black",
            text="N"
        )

        self.rs1sb = tk.Spinbox(self)
        self.rs1sb.place(relx=0.037, rely=0.758, relheight=0.033, relwidth=0.064)
        self.rs1sb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=487.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.rs2sb = tk.Spinbox(self)
        self.rs2sb.place(relx=0.1, rely=0.758, relheight=0.033, relwidth=0.064)
        self.rs2sb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=487.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.stepsb = tk.Spinbox(self)
        self.stepsb.place(relx=0.163, rely=0.758, relheight=0.033, relwidth=0.064)
        self.stepsb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=100.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.nsb = tk.Spinbox(self)
        self.nsb.place(relx=0.226, rely=0.758, relheight=0.033, relwidth=0.064)
        self.nsb.configure(
            activebackground="#f9f9f9",
            background="white",
            foreground="black",
            buttonbackground="#d9d9d9",
            justify="center",
            font="-family {Consolas} -size 14",
            highlightbackground="black",
            relief="flat",
            selectbackground="#c4c4c4",
            from_=0.0,
            to=100.0,
            increment=1.0,
            textvariable=tk.IntVar()
        )

        self.drawspectrebtn = tk.Button(self)
        self.drawspectrebtn.place(relx=0.037, rely=0.800, height=42, width=477)
        self.drawspectrebtn.configure(
            background="#d9d9d9",
            foreground="black",
            activebackground="white",
            font="-family {Consolas} -size 14",
            text="Построить спектр",
            state="disabled",
            command=lambda: view.draw_spectre(ROOT)
        )

        # Additional stuff section.
        self.cmpalgosbtn = tk.Button(self)
        self.cmpalgosbtn.place(relx=0.037, rely=0.861, height=40, width=477)
        self.cmpalgosbtn.configure(
            background="#d9d9d9",
            foreground="black",
            activebackground="white",
            font="-family {Consolas} -size 14",
            text="Сравнение алгоритмов",
            command=lambda: view.compare_algos(ROOT.image)
        )

        self.clrbtn = tk.Button(self)
        self.clrbtn.place(relx=0.037, rely=0.917, height=41, width=477)
        self.clrbtn.configure(
            background="#d9d9d9",
            foreground="black",
            activebackground="white",
            font="-family {Consolas} -size 14",
            text="Очистить экран",
            command=lambda: view.reset(ROOT)
        )


if __name__ == "__main__":
    ROOT = RootWindow()
    ROOT.mainloop()
