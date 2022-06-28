from flask import Flask, request, render_template

app = Flask(__name__)
result = b'null'

@app.route("/rcv", methods = ['GET','POST'])
def rcv():
    global result
    result = request.data
    return result
@app.route("/")
def index():
    global result
    return render_template("index.html", data = result.decode("utf-8"))

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)