import sqlite3
from sqlite3 import Error
from flask import Flask, render_template, request, jsonify

app = Flask(__name__)
data = 0
# verified = False

def create_connection(db_file):
    """ create a database connection to the SQLite database
        specified by the db_file
    :param db_file: database file
    :return: Connection object or None
    """
    conn = None
    try:
        conn = sqlite3.connect(db_file)
    except Error as e:
        print(e)

    return conn


def select_all_tasks(conn):
    """
    Query all rows in the tasks table
    :param conn: the Connection object
    :return:
    """
    cur = conn.cursor()
    cur.execute("SELECT * FROM Temp")

    rows = cur.fetchall()

    for row in rows:
        print(row)

    return rows

@app.route('/index')
def index():
    global data
    database = r"G:\arduino project\testServer\dummydb.db"
    # create a database connection
    conn = create_connection(database)
    with conn:
        data = select_all_tasks(conn)
        


    return render_template("index.html", data=data)

        #else:
        #    return "Unauthorized Card"

    return "Listening..."   

@app.route('/upload', methods=['POST'])
def upload():
    global data
    if request.method == "POST":
        data = request.data
    
    data = data.decode("utf-8")
    temp_val = data.split()
    
    database = r"G:\arduino project\testServer\dummydb.db"
    # create a database connection
    conn = create_connection(database)
    with conn:
        cur = conn.cursor()
        cur.execute("INSERT INTO Temp (Humidity, TempC) VALUES (?, ?)",
            (temp_val[0],temp_val[1]))
        
        return "Ok"
    return "Error"                                                                                                             
  
# main driver function
if __name__ == '__main__':
    app.run(host='0.0.0.0', port = 5000)


# def select_task_by_priority(conn, cardNo):
#     """
#     Query tasks by priority
#     :param conn: the Connection object
#     :param priority:
#     :return:
#     """
#     cur = conn.cursor()
#     cur.execute("SELECT * FROM Names WHERE ID=?", (1,))
#     rows = cur.fetchall()
#     for row in rows:
#         if row[0] == cardNo:
#             return True
#     return False




# @app.route('/enrollment', methods=['GET', 'POST'])
# def enrollment():
#     return render_template("enrollment.html")

# @app.route('/insertData', methods=['POST'])
# def insertData():
#     if request.method == 'POST':
#         name = request.form['idName']
#         cardNumber = request.form['idNumber']
#         database = r"C:\Users\ugv\Downloads\testServer-20220606T100440Z-001\testServer\dummydb.db"
#         # create a database connection
#         conn = create_connection(database)
#         cur = conn.cursor()
#         cur.execute("INSERT INTO userCards (name,cardNo) VALUES (?,?)",(name,cardNumber) )
            
#         conn.commit()
#         print(type(name))
#         print(type(cardNumber))
#         return "Done"

