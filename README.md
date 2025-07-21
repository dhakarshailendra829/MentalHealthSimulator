Introduction:-The Mental Health Console Simulator is a C++ based console application aimed at promoting mental well-being, self-reflection, and mindfulness.
It allows users to log their emotions, track their mood trends, practice breathing exercises, and receive motivational quotes and suggestions based on how they feel.
This project simulates a personal emotional assistant and reinforces good mental health practices in a lightweight, offline, and interactive format.

Objective:- To help users monitor their emotional state over time.
To encourage healthy mental habits like journaling and gratitude.
To provide emotional support via motivational quotes.
To implement practical C++ programming using file handling, string processing, and conditionals.
To promote emotional awareness in a non-intrusive, safe, and offline environment.

Technologies Used:-Feature	Technology/Library Used
                Programming            	C++
                File Handling	        <fstream>
                Time Handling	        <ctime>
              Console Delay	<windows.h> (Sleep() method)
                Random Quote	    <cstdlib>, <vector>

Functional Modules:-
1. Mood Submission
Prompts the user to enter their mood (e.g., happy, sad, anxious).
Saves the mood with a timestamp in moodlog.txt.
Triggers suggestions based on mood type.

2. Motivational Quotes
Loads quotes from quotes.txt.
Randomly selects one quote per session using rand().
Users can add or edit their own quotes (one per line).

3. Breathing Exercises
Simulates a 3-round breathing session:
Inhale → Hold → Exhale (5 seconds each)
Helps reduce anxiety and stress.
Uses timed delays with Sleep() to simulate pacing.

4. Mood History Viewer
Reads and displays previous mood entries.
Helps the user reflect on emotional patterns.


5. Mood Trend Analysis
Parses moodlog.txt and counts:
Number of happy entries.
Number of sad entries.
Total entries.
Last mood recorded.
Displays percentage analysis.

6. Gratitude Journal 
Prompts user to enter one thing they’re grateful for.
Saves it in gratitude.txt.
Encourages positive thinking and emotional grounding.

 Conclusion:- This project demonstrates how simple programming can be used to build meaningful tools that support emotional and mental health.
 It encourages users to reflect on their feelings, build resilience through positive affirmations, and practice mindfulness—all within a beginner-friendly console app.
