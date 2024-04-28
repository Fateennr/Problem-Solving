

class bKashAccount:
    
    def __init__(self, acc_no, name, balance =0):
     self.name = name
     self.acc_no = acc_no
     self.balance = balance
     
    def details(self):        
        details = f"Acc No: {self.acc_no}, Name: {self.name}\nBalance: {self.balance}"
        return details
        
    def addMoney(self, money):
        self.balance = self.balance + money       
        print("Successfully added",money,"Tk to your account")
        
    def sendMoney(self, receiver, amount):
        if self.balance >= amount:
            self.balance -= amount
            receiver.balance += amount
            print("Successfully transferred money!")
        else:
            print(f"Money transfer is unsuccessful due to insufficient balance")
            

    def payBill(self, billers, *biller_amounts):
        for biller_amount in biller_amounts:
            parts = biller_amount.split('_')
            num = int(parts[1])
            if parts[0] in billers:
                if self.balance >= num:
                    self.balance -= num
                    print(f"Your {parts[0]} bill payment is successful!\nCurrent Balance: {self.balance}TK")
                    
                else:
                    print(f"{parts[0]} bill payment is unsuccessful due to insufficient balance.")                       
            else:
                print(f"Sorry, you can't pay your {parts[0]} bill through bKash")
            
            
           
        
billers = ['Desco', 'Titas', 'Dhaka Wasa', 'BTCL']
 
acc1 = bKashAccount('019278', 'Zafar')
acc2 = bKashAccount('018903', 'Abid', 300)

print(acc1.details())
print('----------------1-----------------')
acc1.addMoney(3000)
print('----------------2-----------------')
acc2.sendMoney(acc1,500)
print('----------------3-----------------')
# acc1.payBill(billers, 'Titas_2000')
acc1.payBill(billers, 'Titas_2000', 'Desco_1200')
print('----------------4-----------------')
acc3 = bKashAccount('017262', 'Mostakim', 500)
print(acc2.details())
print(acc3.details())
print('----------------5-----------------')
acc1.sendMoney(acc3,150)
print('----------------6-----------------')
acc2.payBill(billers, 'BTCL_750')
acc3.payBill(billers, 'Dot Internet_1500')
print('----------------7-----------------')
acc2.addMoney(5000)
acc3.addMoney(250)
print('----------------8-----------------')
acc2.payBill(billers, 'BTCL_750')
print('----------------9-----------------')
print(acc2.details())
print('---------------10-----------------')
print(acc3.details())
                
        

    