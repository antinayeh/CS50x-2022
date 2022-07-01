# TODO

from cs50 import get_string




def main():
    text = get_string("Text:" )
    letter = count_letters(text)
    word = count_words(text)
    sentence = count_sentences(text)
    l = (letter / word) * 100
    s = (sentence / word) * 100
    index = round(0.0588 * l - 0.296 * s - 15.8)

    if (index > 16):
        print("Grade 16+")
    elif (index < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(t):
    count = 0
    for i in range (len(t)):
        if (t[i].isalpha()):
            count += 1
    return count


def count_words(t):
    count = 0
    for i in range (len(t)):
        if (t[i].isspace()):
            count += 1
    return count + 1

def count_sentences(t):
    count = 0
    for i in range (len(t)):
        if (t[i] == "." or t[i] == "!" or t[i] == "?"):
            count += 1
    return count


if __name__ == "__main__":
    main()

