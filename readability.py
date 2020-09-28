def main():
    text = input("Text: ")

    letters = count_letters(text)

    words = count_words(text)

    sentences = count_sentences(text)

    # L is the average number of letters per 100 words in the text
    L = (letters / words) * 100

    # S is the average number of sentences per 100 words in the text.
    S = (sentences / words) * 100

    # Calculating grade using Coleman-Liau index
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if (grade < 1):
        print("Before Grade 1")

    elif (grade >= 16):
        print("Grade 16+")

    else:
        print(f"Grade {grade}")

# Helper function to count number of letters


def count_letters(text):
    letters = 0
    length = len(text)
    for i in range(length):
        if text[i].isalpha():
            letters += 1
    return letters

# Helper function to count number of words


def count_words(text):
    words = 1 + text.count(" ")
    return words


# Helper function to count number of sentences


def count_sentences(text):
    sentences = text.count(".") + text.count("!") + text.count("?")
    return sentences


main()