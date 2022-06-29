from flask import Flask, request, render_template

app = Flask(__name__, template_folder="templates")
result = b'null'
data = '0'


@app.route("/rcv", methods=['GET', 'POST'])
def rcv():
    global result
    result = request.data
    return result

@app.route("/data", methods=['GET'])
def getData():
    return data

@app.route("/led")
def led_data():
    global result
    return render_template("led.html", data=result.decode("utf-8"))

@app.route('/turnOn', methods=['POST'])
def turnOn():
    global data
    projectpath = request.form.get('projectFilepath')
    data = "1"
    return render_template("led.html")

@app.route('/turnOff', methods=['POST'])
def turnOff():
    global data
    projectpath = request.form.get('projectFilepath')
    data = "0"
    return render_template("led.html")

@app.route("/")
def index():
    global result
    return render_template("led.html", data=result.decode("utf-8"))


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
