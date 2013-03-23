int userinput;

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop()
{

    userinput = Serial.read();

    if(userinput == 'y')
        digitalWrite(13, HIGH);
    else if(userinput == 'n')
        digitalWrite(13, LOW);
    
    delay(1000);
}
