def repeat(c, times):
    for _ in range(times):
        print(c, end='')

def main():
    while True:
        height_str = input("Height: ")
        if height_str.isdigit():
            height = int(height_str)
            if 1 <= height <= 8:
                break
        print("Height must be a number between 1 and 8")

    for i in range(height):
        num_spaces = height - i - 1
        num_hashes = i + 1

        repeat(' ', num_spaces)
        repeat('#', num_hashes)

        print()

if __name__ == "__main__":
    main()