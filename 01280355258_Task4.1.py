#
#      Author:Mahmoud Esam Ali    
#      Date : 2023-Aug-27

#
import random
import numpy as np

class Villain():
    def __init__(self, name, health, energy):
        self.name = name
        self.health = health
        self.energy = energy
        self.weapons = []
        self.shields = []

    def attack (self, villain,Damage ,Energy,Name,Resources):
        #weapon = random.choice(self.weapons)
        damage = Damage

        if Resources >0 : 
            if Name == "Kalman Missile":
                print(f"{villain.name} can not defended the attack with Kalman Missile")
                self.energy -= Energy
                villain.health -= damage
                print(f"{villain.name} received {damage} damage from {self.name}")
            else:
                self.energy -= Energy
                villain.defend(self, Damage,Name)
        else:
            print(f"you can not attack with {Name} any more")  
            weapon = random.choice(self.weapons)
            damage = weapon.Damage
            self.energy -= weapon.energy
            villain.health -= damage
            print(f"{villain.name} received {damage} damage from {self.name}")          

        
    def defend(self, villain, Damage,Name):
        if Name =="Gru":
            i = int(input("choose a shield, if Gru attack(Energy Net Trap(0),Quantum Deflector(1)):"))
            shield = self.shields[i]
            save = shield.save
            self.energy -= shield.energy

            self.health -= Damage - (save*Damage)
            print(f"{self.name} defended the attack with {shield.name}")
            print(f"{self.name} received {Damage - (save*Damage)} damage from {villain.name}")
        else:
            i = int(input("choose a shield, if Vector attack(Energy-Projected BarrierGun(0),Selective Permeability(1)):"))
            shield = self.shields[i]
            save = shield.save
            self.energy -= shield.energy

            self.health -= Damage - (save*Damage)
            print(f"{self.name} defended the attack with {shield.name}")
            print(f"{self.name} received {Damage - (save*Damage)} damage from {villain.name}")


class Weapon:
    def __init__(self,name, energy,Damage,resources):
        self.name = name
        self.energy = energy
        self.Damage = Damage
        self.resources = resources

class Shield:
    def __init__(self, name, save,energy , resources):
        self.name = name
        self.save = save
        self.energy = energy
        self.resources = resources

# Create two villains
villain1 = Villain("Gru", 100, 500)
villain2 = Villain("Vector", 100, 500)

 # Create the weapons
weapon1 = Weapon("Freeze Gun", 50, 11, np.inf)
weapon2 = Weapon("Electric Prod", 88, 18, 5)
weapon3 = Weapon("Mega Magnet", 92, 10, 3)
weapon4 = Weapon("Kalman Missile", 120, 20, 1)
weapon5 = Weapon("Laser Blasters", 40, 8, np.inf)
weapon6 = Weapon("Plasma Grenades", 56, 13, 8)
weapon7 = Weapon("Sonic Resonance Ca", 100, 22, 3)
# Create the shields
shield1 = Shield("Energy-Projected BarrierGun", 0.4, 20,100)
shield2 = Shield("Selective Permeability", 0.9, 50,2)
shield3 = Shield("Energy Net Trap", 0.32, 15,100)
shield4 = Shield("Quantum Deflector", 0.8, 40,3)

# Add the weapons and shields to the villains
#villain1(Gru)
villain1.weapons.append(weapon1)
villain1.weapons.append(weapon2)
villain1.weapons.append(weapon3)
villain1.weapons.append(weapon4)
villain1.shields.append(shield1)
villain1.shields.append(shield2)
#villain1(Vector)
villain2.weapons.append(weapon5)
villain2.weapons.append(weapon6)
villain2.weapons.append(weapon7)
villain2.shields.append(shield3)
villain2.shields.append(shield4)

# Start the battle
rounds = 1

while (villain1.health > 0 and villain2.health > 0) and (villain1.energy >0 and villain2.energy >0):
    print(f"Round {rounds}")

    choice = input("Choose a villain to Attack with (Gru or Vector): ")
    if choice == "Gru":
        #villain1.attack(villain2,Weapon.Damage)
        hit = input("choose a weapon to attack with(Freeze_Gun(0),Electric_Prod(1),Mega_Magnet(2),Kalman_Missile(3)): ")
        if hit =="0":
            villain1.attack(villain2,weapon1.Damage,weapon1.energy,weapon1.name,weapon1.resources)
            weapon1.resources -= 1
        elif hit =="1": 
            villain1.attack(villain2,weapon2.Damage,weapon2.energy,weapon2.name,weapon2.resources)
            weapon2.resources -= 1
        elif hit =="2":
            villain1.attack(villain2,weapon3.Damage,weapon3.energy,weapon3.name,weapon3.resources)
            weapon3.resources -= 1
        elif hit =="3":
            villain1.attack(villain2,weapon4.Damage,weapon4.energy,weapon4.name,weapon4.resources) 
            weapon4.resources -= 1
        else :
            print("Wrong Weapon Id")
            break             
    elif choice == "Vector":
        hit = input("choose a weapon to attack with(Laser Blasters(0),Plasma Grenades(1),Sonic Resonance Ca(2)): ")
        if hit =="0":
            villain2.attack(villain1,weapon5.Damage,weapon5.energy,weapon5.name,weapon5.resources)
            weapon5.resources -= 1
        elif hit =="1": 
            villain2.attack(villain1,weapon6.Damage,weapon6.energy,weapon6.name,weapon6.resources)
            weapon6.resources -= 1
            
        elif hit =="2":
            villain2.attack(villain1,weapon7.Damage,weapon7.energy,weapon7.name,weapon7.resources)
            weapon7.resources -= 1
        
        else :
            print("Wrong Weapon Id")   
            break
        
    else :
        
        break                   


    print(f"{villain1.name} health: {villain1.health}")
    print(f"{villain1.name} Energy: {villain1.energy}")
    print(f"{villain2.name} health: {villain2.health}")
    print(f"{villain2.name} Energy: {villain2.energy}")

    rounds += 1

# Show the winner
if villain1.health <= 0:
    print(f"{villain2.name} wins!")
elif villain2.health <= 0:
    print(f"{villain1.name} wins!")