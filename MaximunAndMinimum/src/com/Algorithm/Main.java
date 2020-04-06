package com.Algorithm;

import java.util.Scanner;

public class Main {

    static class Pair {
        public int max;
        public int min;
    }

    public static Pair findMaxMin(int[] arr, int start, int end) {
        Pair minmax , left, right;
        minmax = new Pair();
        left = new Pair();
        right = new Pair();

        if(start == end) {
            minmax.min = arr[start];
            minmax.max = arr[start];
            return minmax;
        }

        if(start + 1 == end) {
            if(arr[start] > arr[end]) {
                minmax.max = arr[start];
                minmax.min = arr[end];
            }
            else {
                minmax.max = arr[end];
                minmax.min = arr[start];
            }
            return minmax;
        }

        int mid = (start + end)/2;
        left = findMaxMin(arr, start, mid);
        right = findMaxMin(arr, mid+1, end);

        if(left.min < right.min) {
            minmax.min = left.min;
        }
        else {
            minmax.min = right.min;
        }
        if(left.max > right.max) {
            minmax.max = left.max;
        }
        else {
            minmax.max = right.max;
        }
        return minmax;
    }

    public static void main(String[] args) {
	    int [] arr;
        Scanner s = new Scanner(System.in);

        System.out.println("Enter the size of the array :- ");
        int n = s.nextInt();
        arr = new int [n];

        System.out.println("Enter the elements of the array :- ");
        for (int i = 0; i < n; i++)
        {
            System.out.print("Enter the " + i + " element :- ");
            arr[i] = s.nextInt();
        }

        Pair p = findMaxMin(arr, 0, n-1);
        System.out.println("The maximum element :- " + p.max + " The minimum element :- " + p.min);
    }
}
