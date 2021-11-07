#include "network.h"


int main() {
	srand(69);

	Network n = Network({3, 3, 2, 2});
	vector<float> input_vector = {-0.01, 0.1, 0.01};
	printf("Automatic network creation:\n");
	printf("Input neurons:\n");
	for (auto input: input_vector) {
		printf("%f\n", input);
	}

	n.propagate(input_vector);
	printf("Output neurons:\n");
	for (auto output: n.get_result()) {
		printf("%f\n", output);
	}
	printf("Softmaxed output neurons:\n");
	for (auto output: Softmax::GetInstance().get_result()) {
		printf("%f\n", output);
	}

	n.add_input_neuron();
	input_vector.push_back(-3);
	printf("Expanded neural network:\n");
	printf("Input neurons:\n");
	for (auto input: input_vector) {
		printf("%f\n", input);
	}

	n.propagate(input_vector);
	printf("Output neurons:\n");
	for (auto output: n.get_result()) {
		printf("%f\n", output);
	}
	printf("Softmaxed output neurons:\n");
	for (auto output: Softmax::GetInstance().get_result()) {
		printf("%f\n", output);
	}


	return 0;
}