from playsound import playsound
import sys
canshu = str(sys.argv[1])
path = "piano\\" + canshu + ".mp3"
playsound(path)
exit(1)
