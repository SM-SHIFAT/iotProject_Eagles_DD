import sqlite3

def createTable(conn):
    conn.execute("CREATE TABLE IF NOT EXISTS inventory (item TEXT, price INTEGER)")
    conn.commit()
    
def insertData(conn):
    conn.execute("INSERT INTO inventory VALUES('rock', 100)")
    conn.commit()
    
def showData(conn):
    cursor = conn.execute("SELECT * FROM inventory")
    results = cursor.fetchall()
    print(results)
    
conn = sqlite3.connect(r'G:\arduino project\IoTPractical\Database\test.db')
createTable(conn)
insertData(conn)
showData(conn)
conn.close()
