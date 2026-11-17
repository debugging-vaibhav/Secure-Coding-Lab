import os

folder = os.path.abspath("safe_files")
filename = input("Enter filename: ")

try:
    filepath = os.path.abspath(os.path.join(folder, filename))

    if os.path.commonpath([folder, filepath]) != folder:
        print("Access denied: Invalid file path")
    elif not os.path.isfile(filepath):
        print("Error: File not found")
    else:
        with open(filepath, "r", encoding="utf-8") as file:
            print(file.read())

except (OSError, ValueError) as error:
    print("Error:", error)
