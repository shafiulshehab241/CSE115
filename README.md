Typing Speed Test Program 

This project is a Typing Speed Test written in C. It measures:
-Typing Speed (WPM)
-Accuracy (%)
-Time taken to type a given sentence

The program randomly selects a sentence from a text file, waits for the user to start, then calculates the results based on input.


---

📌 Features

Reads a random line from a sample.txt file

Measures time with microsecond precision

Calculates:

Word count

Words Per Minute (WPM)

Accuracy using character-by-character comparison


Displays results in color-coded output:

🟢 High speed & accuracy

🟡 Average performance

🔴 Needs improvement




---

📁 Required Files

main C file (your program)

sample.txt containing at least 10 lines of sample sentences

Example sample.txt content:

Sentence one.
Sentence two.
Sentence three.
...


---

▶ How It Works

1. The program picks a random sentence from sample.txt.
2. User presses Enter to begin.
3. Timer starts as soon as the user begins typing.
4. User types the displayed sentence and presses Enter.
5. Program calculates:

Time taken
Words typed
WPM
Accuracy

6. Results are displayed with color formatting.




---

🧮 Formulas Used

Words Per Minute (WPM)

WPM = (WordCount / TimeInSeconds) * 60

Accuracy

Accuracy = (CorrectCharacters / TotalCharactersInOriginalText) * 100


---

🛠 Compile & Run

Compile:

gcc typing_test.c -o typing_test

Run:

./typing_test


---






