const int triggerOne = 2;
const int echoOne = 3;
const int triggerTwo = 4;
const int echoTwo = 5;

void setup()
{
    Serial.begin(9600);
    pinMode(triggerOne, OUTPUT);
    pinMode(echoOne, INPUT);
    pinMode(triggerTwo, OUTPUT);
    pinMode(echoTwo, INPUT);
}

int calculate_distance(int trigger, int echo)
{
    // Clear state
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    // Trigger an ultrasonic sound pulse
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    // Stop the sound pulse
    digitalWrite(trigger, LOW);

    long timeCaptured = pulseIn(echo, HIGH);
    long distance = timeCaptured * 0.034 / 2;
    if (distance > 50)
    {
        distance = 50;
    }

    return distance;
}

void loop()
{
    int distanceLeft = calculate_distance(triggerOne, echoOne);
    int distanceRight = calculate_distance(triggerTwo, echoTwo);

    if ((distanceLeft < 30 && distanceRight < 30))
    {
        Serial.println("play");
        delay(1000);
    }

    if (distanceLeft > 45 && (distanceRight < 30 && distanceRight > 20))
    {
        Serial.println("volumedown");
        delay(100);
    }

    if (distanceRight > 45 && (distanceLeft < 30 && distanceLeft > 20))
    {
        Serial.println("volumeup");
        delay(100);
    }

    delay(200);
}
