# 웹 프레임워크!! back-end
# flask run -> 웹 공부를 하고 싶으면 검색!!
# jdango, flask, fastapi ....
# gradio (머신 러닝.. openUI..)
# streamlit (대시보드)
# Dash (데이터 시각화!!)

# GUI 프로그램
# pythonQT, tkinter -> window program
# pygame, matplotlib, openCV
# windows OS -> C#, MSC(C++)
# linux -> SDL, vulkan...
# Unity, Unreal...

# AI 간련 라이브러리
# numpy, pandas, matplotlib, tensorflow ( keras ), pytorch, sk-learn
# orange3

from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello():
    return "<h1>Hello world! I'm Python Flask!!</h1>"