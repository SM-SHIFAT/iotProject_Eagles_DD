from flask import Flask, render_template, request, jsonify

app = Flask(__name__)
data = b'null'

@app.route('/hello', methods=['GET', 'POST'])
def hello_world():
    global data
    data = request.data
    return data

@app.route('/index')
def index():
    return render_template("index.html", data=data.decode("utf-8"))
  
# main driver function
if __name__ == '__main__':
    app.run(host='0.0.0.0', port = 5000)