#pragma once
#define RANDF ((float) rand()) / (float) RAND_MAX

#include <random>
#include "iobject.h"
#include "link.h"

struct Neuron : public IObject {
	float weight;
	float bias;
	float result;
	Link link;

	Neuron() {
		weight = RANDF;
		bias = 0;
		result = 0;
	}

	Neuron(Link link) : Neuron() {
		this->link = link;
	}

	Neuron(float w, float b, Link link) {
		weight = w;
		bias = b;
		this->link = link;
		result = 0;
	}

	virtual Data on_send() override {
		Data ret = Data{(result)};
		result = 0;
		return ret;
	};

	virtual void on_receive(Data data) override {
		result += data.value * weight + bias;
		link.on_receive({(result)});
	};

	virtual IObject *clone() override {
		return new Neuron(weight, bias, link);
	}
};

