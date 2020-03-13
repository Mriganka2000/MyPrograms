package com.Algorithm;

import java.util.Scanner;

public class Main {
    public static void Longest_Common_Subsequence(String x, String y) {
        int m = x.length();
        int n = y.length();
        int[][] c = new int [m+1][n+1];

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    c[i][j] = 0;
                }
                else if(x.charAt(i-1) == y.charAt(j-1)) {
                    c[i][j] = c[i-1][j-1]+1;
                }
                else if(c[i-1][j] >= c[i][j-1]) {
                    c[i][j] = c[i-1][j];
                }
                else {
                    c[i][j] = c[i][j-1];
                }
            }
        }

        int index = c[m][n];
        int i = m;
        int j = n;
        char[] sequence = new char[index+1];
        sequence[index] = ' ';
        int temp = index;

        while(i > 0 && j > 0) {
            if(x.charAt(i-1) == y.charAt(j-1)) {
                sequence[index-1] = x.charAt(i-1);
                i--;
                j--;
                index--;
            }
            else if(c[i-1][j] > c[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
        System.out.println("The longest common subsequence is :- ");
        for (int k = 0; k <= temp; k++) {
            System.out.print(sequence[k]);
        }
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the first string :- ");
        String s1 = s.nextLine();
        System.out.println("Enter the second string :- ");
        String s2 = s.nextLine();

        Longest_Common_Subsequence(s1, s2);
    }
}
