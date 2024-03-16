import sys

def load_banned_words(filename):
    try:
        with open(filename, 'r') as file:
            banned_words = set(word.strip().lower() for word in file)
        return banned_words
    except FileNotFoundError:
        print("File not found:", filename)
        sys.exit(1)

def censor_message(message, banned_words):
    tokens = message.split()
    censored_tokens = []
    for token in tokens:
        if token.lower() in banned_words:
            censored_tokens.append('*' * len(token))
        else:
            censored_tokens.append(token)
    return ' '.join(censored_tokens)

def main():
    if len(sys.argv) != 2:
        print("Usage: python bleep.py dictionary")
        sys.exit(1)

    banned_words = load_banned_words(sys.argv[1])

    message = input("What message would you like to censor?\n")

    censored_message = censor_message(message, banned_words)

    print(censored_message)

if __name__ == "__main__":
    main()
