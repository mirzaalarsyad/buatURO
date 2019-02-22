import random
import sys
import math

totalplatinum=0
chance={}
zoneswithplatinum=[]

player_count, my_id, zone_count, link_count = [int(i) for i in input().split()]
for i in range(zone_count):
   zone_id, platinum_source = [int(i) for i in input().split()] #baca platinum zone
   zoneswithplatinum.append(platinum_source)
   
for i in range(link_count): #zona bersebelahan
   zone1, zone2 = [int(i) for i in input().split()]
   if zone1 not in chance:
       chance[zone1]=[]
   if zone2 not in chance:
       chance[zone2]=[]
   if zone2 not in chance[zone1]:
       chance[zone1].append(zone2)
   if zone1 not in chance[zone2]:
       chance[zone2].append(zone1)

# game loop
while True:
   zones= []
   zone_present = []
   my_zones = [] 
   posisi = ""
   muncul = ""
   
   platinum = int(input()) # platinum tersedia

   for i in range(zone_count): #posisi kami
       zId, ownerId, podsP0, pods_P1, podsP2, podsP3 = [int(i) for i in input().split()]
       exec("count=podsP"+str(my_id))
       zones.append(ownerId)
       if count:
           zone_present.append([zId,ownerId,count])
   for zone in zone_present:
       if zone[1] == my_id:
           peluang = random.randint(0,len(chance[zone[0]])-1)
           posisi += str(zone[2])+" "+str(zone[0])+" "+str((chance[zone[0]])[peluang])+" "
   #bergerak
   for zone in range(len(zones) - 1):
       if zones[zone] == my_id:
           totalplatinum += zoneswithplatinum[zone]
           my_zones.append(zone)
   while totalplatinum >= 20:
       peluang = random.randint(0,len(my_zones)-1)
       muncul += "1 "+str(my_zones[peluang])+" "
       totalplatinum-=20
   
   #Instruksi gerakan pod
   print(posisi) 
   print(muncul) #selesai