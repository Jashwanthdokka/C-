main(){
int stream Chan;
int i;
int r = 4;
int s;
send (Chan,r);
forall i = 1 to 5 do {
recv(Chan, s);
cout << "S is"  << s << ENDL;
}
}