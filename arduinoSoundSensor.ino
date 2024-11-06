// represents the pin number connected to sensor
const int outputData = 8;

// intervals between each data print
const int initialTime = 10;

// holds current time value
unsigned long millisCurrent;

// stores last timmestamp when data is printed
unsigned long millisLast = 0;

// stores calculated elapsed time since last print
unsigned long millisElapsed = 0;

// stores count events
int sampleBufferValue = 0;

void setup() {
    // serial communication initialization
    Serial.begin(9600);
}

void loop() {
    // recording current time
    millisCurrent = millis();

    // calculate time since last data print
    millisElapsed = millisCurrent - millisLast;

// checks if LOW and increment sampleBufferValue to increment by 1
    if (digitalRead(outputData) == LOW) {
        sampleBufferValue++;
    }

// checks if elapsed time is greater than 10 milliseconds
    if (millisElapsed > initialTime) {
        Serial.println(sampleBufferValue);

        // value reseting
        sampleBufferValue = 0;
        millisLast = millisCurrent;
    }
}