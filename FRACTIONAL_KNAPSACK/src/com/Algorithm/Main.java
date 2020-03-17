package com.Algorithm;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static class Item {
        Double cost;
        double index, weight, value;
        public Item(double index, double weight, double value) {
            this.index = index;
            this.weight = weight;
            this.value = value;
            cost = value / weight;
        }
    }

    public static void Fractional_Kanpsack(int weight[], int value[], int maxWeight) {
        Item [] items = new Item[weight.length];

        for (int i = 0; i < weight.length; i++) {
            items[i] = new Item(i, weight[i], value[i]);
        }

        Arrays.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item o1, Item o2) {
                return o2.cost.compareTo(o1.cost);
            }
        });

        double totalValue = 0d;
        int currentWeight = 0;

        for (Item i : items) {
            if(currentWeight + i.weight <= maxWeight) {
                currentWeight += i.weight;
                totalValue += i.value;
            }
            else {
                int remain = maxWeight - currentWeight;
                totalValue += i.value * ((double)remain / i.weight);
            }
        }
        System.out.println("The maximum cost can be get is :- " + totalValue);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n, maxWeight;
        int weight[], value[];

        System.out.print("Enter the number of the items :- ");
        n = s.nextInt();
        weight = new int[n];
        value = new int[n];
        System.out.println("Enter the value and weight of the items :- ");
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the value of the item " + i + " :- ");
            value[i] = s.nextInt();
            System.out.print("Enter the weight of the item " + i + " :- ");
            weight[i] = s.nextInt();
        }
        System.out.print("Enter the maximum weight of the knapsack :- ");
        maxWeight = s.nextInt();

        Fractional_Kanpsack(weight, value, maxWeight);
    }
}
