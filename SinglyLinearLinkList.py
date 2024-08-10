class Node:
    def __init__(self,Data) -> None:
        self.data = Data
        self.next = None

class LinkList:
    
    __Node_Count = None
    def __init__(self) -> None:
        self.Head = None
        self.__Node_Count = 0


    def InsertAtFirst(self,data):
            New_Node = Node(data)
            if self.Head is None:
                self.Head = New_Node
                self.__Node_Count +=  1
                return
            else:
                New_Node.next = self.Head
                self.Head = New_Node
                self.__Node_Count +=  1


    def InsertAtEnd(self,Data): # InsertAtPos(data)
        New_Node = Node(Data)
        if self.Head is None:
            self.Head = New_Node
            self.__Node_Count +=  1
            return
        Current_Node = self.Head
        while(Current_Node.next):
            Current_Node = Current_Node.next
        Current_Node.next = New_Node   
        self.__Node_Count +=  1

    def InsertAtIndex(self,Data,Index):
        if(Index > self.__Node_Count + 1  and Index < 1):
            print("Invalid Index")
            return
        if Index == 1:
            self.InsertAtFirst(Data)
            return
        if Index == self.__Node_Count:
            self.InsertAtEnd(Data)
            return
        Current_Node = self.Head
        for i in range(Index -1):
            Current_Node = Current_Node.next
        if Current_Node != None:
            New_Node = Node(Data)
            New_Node.next = Current_Node.next
            Current_Node.next = New_Node
            self.__Node_Count += 1
        else:
            print("Invalid Pos")    


    def DeleteFirstNode(self):
        if (self.Head == None):
            return
        self.Head = self.Head.next
        self.__Node_Count -=  1

    def DeleteLastNode(self):
        if self.Head is None:
            return
        Current_Node = self.Head

        if self.__Node_Count > 1:
            while(Current_Node != None and Current_Node.next.next != None):
                Current_Node = Current_Node.next
        Current_Node.next = None  
        self.__Node_Count -=  1  

    def DeleteAtPosistion(self,Index):
        if(Index > self.__Node_Count + 1  and Index < 1):
            print("Invalid Index")
            return
        if Index == 1:
            self.DeleteFirstNode()
            return
        if Index == self.__Node_Count:
            self.DeleteLastNode()
            return
        Current_Node = self.Head
        for I in range(Index -1):
            Current_Node = Current_Node.next
        if Current_Node != None:
            Current_Node.next = Current_Node.next.next
            self.__Node_Count -=  1
        else:
            print("Index out of range")    


    def DispayLL(self):
        Current_Node = self.Head
        if Current_Node == None:
            print("LL is Empty")
            return
        nodes = self.__Node_Count
        while(nodes != 0):
            print("|", Current_Node.data,"| ->",end = " ")
            Current_Node = Current_Node.next
            nodes -= 1
        print("None")


    def SizeLL(self):
        print(self.__Node_Count)
        return self.__Node_Count


def main():
    print("--------Singly Linear LInk list ------------------")
    LOBJ = LinkList()
    LOBJ.InsertAtFirst(11)
    LOBJ.InsertAtFirst(21)
    LOBJ.InsertAtFirst(101)
    LOBJ.InsertAtEnd(151)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DeleteFirstNode()
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DeleteLastNode()
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DeleteLastNode()
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DeleteLastNode()
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DispayLL()
    LOBJ.InsertAtFirst(101)
    LOBJ.InsertAtFirst(11)
    LOBJ.InsertAtEnd(151)
    LOBJ.InsertAtEnd(51)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.InsertAtIndex(121,2)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.InsertAtIndex(501,3)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.InsertAtIndex(521,4)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DeleteLastNode()
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.InsertAtIndex(521,-7)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DeleteAtPosistion(3)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())
    LOBJ.DeleteAtPosistion(2)
    LOBJ.DispayLL()
    print("Number node in LL is ",LOBJ.SizeLL())


if __name__ == "__main__":
    main()

