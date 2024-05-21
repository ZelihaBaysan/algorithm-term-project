import sqlite3

def create_database():
    conn = sqlite3.connect('passwords.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS passwords
                 (id INTEGER PRIMARY KEY AUTOINCREMENT, 
                  platform TEXT, 
                  password TEXT)''')
    conn.commit()
    conn.close()

def save_password_to_db(platform, password):
    conn = sqlite3.connect('passwords.db')
    c = conn.cursor()
    c.execute("INSERT INTO passwords (platform, password) VALUES (?, ?)", (platform, password))
    conn.commit()
    conn.close()

def create_password_dict():
    mainParts = {}

    # Şifre alma ve doğrulama
    while True:
        password = input("Lutfen 6 haneli bir sifre giriniz: ")
        if len(password) == 6 and password.isdigit():
            mainParts['password'] = password
            break
        else:
            print("sifre 6 haneli olmali ve rakamlardan olusmali. Lutfen tekrar deneyin.")

    # Platform adı alma ve doğrulama
    while True:
        platform = input("Kullandiginiz platform adini giriniz: ").strip()
        if len(platform) >= 2:
            first_last = platform[0] + platform[-1]
            mainParts['platform'] = first_last
            break
        else:
            print("Platform adi en az 2 karakterden olumalidir. Lutfen tekrar deneyin.")

    return mainParts

def create_custom_password():
    mainParts_dict = create_password_dict()

    while True:
        choice = input("Platform adini basa eklemek icin 'B', sona eklemek icin 'S' yaziniz: ").strip().upper()
        if choice in ['B', 'S']:
            password = mainParts_dict['password']
            platform = mainParts_dict['platform']
            if choice == 'B':
                custom_password = platform + password
            else:
                custom_password = password + platform

            # Veritabanına kaydetme
            save_password_to_db(platform, custom_password)
            break
        else:
            print("Gecersiz secim.")

    print(f"Olusturulan sifre: {custom_password}")

# Veritabanını oluştur
create_database()

# Özel şifre oluştur ve veritabanına kaydet
create_custom_password()
