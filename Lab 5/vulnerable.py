import os

folder = "safe_files"
filename = input("Enter filename: ")
filepath = os.path.join(folder, filename)

try:
    with open(filepath, "r", encoding="utf-8") as file:
        print(file.read())
except (OSError, ValueError) as error:
    print("Error:", error)
