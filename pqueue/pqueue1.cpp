#include <iostream>
#include <cassert>
#include "pqueue1.h"
	PriorityQueue::PriorityQueue() {
		head_ptr = nullptr;
	}

	PriorityQueue::PriorityQueue(const PriorityQueue& source) {
		if (source.head_ptr == nullptr) {
			this->head_ptr = nullptr;
			return;
		}

		Node* tmp = nullptr;
		this->head_ptr = new Node{ source.head_ptr->priority, source.head_ptr->data, nullptr };
		tmp = this->head_ptr;

		const Node* s = source.head_ptr->link;
		while (s != nullptr) {
			tmp->link = new Node{ s->priority, s->data, nullptr };
			tmp = tmp->link;
			s = s->link;
		}
	}
	PriorityQueue::~PriorityQueue() {
		Node* temp;
		while (head_ptr != nullptr) {
			temp = head_ptr->link;
			delete head_ptr;
			head_ptr = temp;
		}
	}

	size_t PriorityQueue::size() const {
		Node* temp = head_ptr;
		size_t size = 0;
		while (temp != nullptr) {
			temp = temp->link;
			++size;
		}
		return size;
	}

	void PriorityQueue::insert(const Node::Item& entry, unsigned int priority) {
		Node* tmp = this->head_ptr;
		Node* tmp_ptr = new Node{ priority, entry, nullptr };

		if (tmp == nullptr) {
			this->head_ptr = tmp_ptr;
			return;
		}

		if (priority > tmp->priority) {
			tmp_ptr->link = tmp;
			this->head_ptr = tmp_ptr;
			return;
		}

		while ((tmp->link != nullptr) && (tmp->link->priority >= priority)) {
			tmp = tmp->link;
		}

		tmp_ptr->link = tmp->link;
		tmp->link = tmp_ptr;
	}

	Node::Item PriorityQueue::get_front() {
		assert(this->head_ptr != nullptr);
		Item tmp{ this->head_ptr->data };
		Node* tmp_ptr = this->head_ptr->link;
		delete head_ptr;
		head_ptr = tmp_ptr;
		return tmp;
	}

	void PriorityQueue::operator= (const PriorityQueue& source) {
		if (this == &source) {
			return;
		}
		Node* tmpclear;
		while (this->head_ptr != nullptr) {
			tmpclear = head_ptr->link;
			delete head_ptr;
			head_ptr = tmpclear;
		}
		if (source.head_ptr == nullptr) {
			this->head_ptr = nullptr;
			return;
		}

		Node* temp = nullptr;
		this->head_ptr = new Node{ source.head_ptr->priority, source.head_ptr->data, nullptr };
		temp = this->head_ptr;
		const Node* s = source.head_ptr->link;
		while (s != nullptr) {
			temp->link = new Node{ s->priority, s->data, nullptr };
			temp = temp->link;
			s = s->link;
		}
	}