__author__ = 'William'
import serial
import math as math
import pygame
from pygame.locals import *
from sys import exit

def Print(text):
    screen.blit(font.render(text, True, (0, 0, 0)), [10, 10])

ser = serial.Serial("COM3", 9600, timeout=3)

pygame.init()
pygame.joystick.init()
clock = pygame.time.Clock()

SCREEN_SIZE = (800, 600)
screen = pygame.display.set_mode(SCREEN_SIZE, 0, 32)

font = pygame.font.SysFont("arial", 16)
font_height = font.get_linesize()
event_text = []

throttleVal = 0

while True:
    screen.fill((255, 255, 255))
    event = pygame.event.wait()
    joystickCount = pygame.joystick.get_count()

    if joystickCount > 0:
        joystick = pygame.joystick.Joystick(0)
        joystick.init()
        axis = joystick.get_axis(2)
        # axis goes from -1 to 1
        # need to convert to a positive 0 - 2
        throttleVal = axis + 1
        v = int(math.floor(throttleVal / 2 * 255))
        Print('Throttle value %s' % v)
        try:
            ser.write("%s" % v)
        except serial.SerialException:
            print("Time out exception")
    if event.type == QUIT:
        exit()

    pygame.display.flip()

    clock.tick(2)

