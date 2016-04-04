// Set constants to repesent the low note and high note frequencies
const int lowFreq = 220;        // A3: This is the A below Middle C
const int highFreq = 880;       // A5: This is the A two octaves above Middle C

// Set constants to repesent the low joystick and high joystick positions
const int lowJoystick = 40;     // Joystick pushed all the way in one direction
const int highJoystick = 1050;  // Joystick pushed all the way in the other direction

// Connect speaker to digital pin 11 and ground
const int SPEAKER_PIN = 11;

// The 'slope' (m) and 'intercept' (b) of the linear function that will 
// convert from the joystick value to a frequency
// It's your job to figure out what these numbers should be
// Please read the assignment page for more information
//float m = 
//float b = 

// Gets the current joystick position
// Joystick should be plugged into the A5 (analog 5) pin
int getJoystick() {
  return analogRead(A5);
}

// Compute the frequency given the joystick position using the 
// m (slope) and b (intercept) of the linear equation that converts
// the joystick position to a frequency.  See the assignment
// sheet for more information
int getFreq(int joystick) {
  return joystick * m + b;
}

// Setup code to open the serial port that will monitor the
// joystick position
void setup() {
  Serial.begin(9600);
}

// Main program loop
void loop() {
  // Get the joystick position
  int js = getJoystick();
  
  // Print the 'm', 'b', joystick position, and frequency for debug
  Serial.print(m);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" ");
  Serial.print(js);
  Serial.print(" ");
  Serial.println(getFreq(js));

  // Compute the frequency given the joystick position
  int freq = getFreq(js);

  // Send the frequency to the speaker.
  tone(SPEAKER_PIN, freq);
}


