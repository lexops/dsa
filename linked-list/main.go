package main

import (
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	value int
	next  *Node
}

func addNode(head **Node, value int) {
	// No need to malloc(sizeof(Node))
	// Thus no need for null checking
	newNode := &Node{
		value: value,
		// next:  nil,
		// Also no need to set newNode.next to nil
		// The zero value for pointer in Go is nil
	}

	if *head == nil {
		newNode.next = nil
	} else {
		// Go can infer tmp is *Node
		tmp := *head
		newNode.next = tmp
	}

	newNode.value = value
	*head = newNode
}

func revertList(head **Node) {
	var prev *Node
	curr := *head

	for curr != nil {
		next := curr.next
		curr.next = prev
		prev = curr
		curr = next
	}

	*head = prev
}

func printList(head *Node) {
	curr := head

	for curr != nil {
		fmt.Printf("%d -> ", curr.value)
		curr = curr.next
	}

	fmt.Println("NULL")
}

func main() {
	var head *Node

	for i := 1; i < len(os.Args); i++ {
		value, _ := strconv.Atoi(os.Args[i])
		addNode(&head, value)
	}

	revertList(&head)

	printList(head)

	// No need to implement a deleteList
	// since Golang has a Garbage Collector

	// deleteList(head)

}
