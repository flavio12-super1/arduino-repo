#include <IRremote.h>

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver); // create instance of 'irrecv'
bool ledState;

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received
// describing Remote IR codes
{

    switch (irrecv.decodedIRData.decodedRawData)
    {
    case 0xBA45FF00:
    {
        Serial.println("POWER");
        // Respond to POWER button
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState);
    }
    break;
    case 0xB847FF00:
        Serial.println("FUNC/STOP");
        break;
    case 0xB946FF00:
        Serial.println("VOL+");
        break;
    case 0xBB44FF00:
        Serial.println("FAST BACK");
        break;
    case 0xBF40FF00:
        Serial.println("PAUSE");
        break;
    case 0xBC43FF00:
        Serial.println("FAST FORWARD");
        break;
    case 0xF807FF00:
        Serial.println("DOWN");
        break;
    case 0xEA15FF00:
        Serial.println("VOL-");
        break;
    case 0xF609FF00:
        Serial.println("UP");
        break;
    case 0xE619FF00:
        Serial.println("EQ");
        break;
    case 0xF20DFF00:
        Serial.println("ST/REPT");
        break;
    case 0xE916FF00:
        Serial.println("0");
        break;
    case 0xF30CFF00:
        Serial.println("1");
        break;
    case 0xE718FF00:
        Serial.println("2");
        break;
    case 0xA15EFF00:
        Serial.println("3");
        break;
    case 0xF708FF00:
        Serial.println("4");
        break;
    case 0xE31CFF00:
        Serial.println("5");
        break;
    case 0xA55AFF00:
        Serial.println("6");
        break;
    case 0xBD42FF00:
        Serial.println("7");
        break;
    case 0xAD52FF00:
        Serial.println("8");
        break;
    case 0xB54AFF00:
        Serial.println("9");
        break;
    default:
        Serial.println("Other button:");
        break;
    }

    delay(100);
} // END translateIR

void setup() /*----( SETUP: RUNS ONCE )----*/
{
    Serial.begin(9600);
    Serial.println("IR Receiver Button Decode");
    irrecv.enableIRIn(); // Start the receiver

    // Set up LED
    ledState = false;
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, ledState);
}
/*--(end setup )---*/

void loop() /*----( LOOP: RUNS CONSTANTLY )----*/
{
    if (irrecv.decode()) // have we received an IR signal?
    {
        translateIR();
        irrecv.resume(); // receive the next value
    }
} /* --(end main loop )-- */
