#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n =nums2.size();
        vector<int>ng(n,-1);
        stack<int>st;
       // map<int,int>mp;
        for (int i = 2*n -1 ; i >=0 ; i--) //Traverse backward  to fill stack with big vlaues first 
        {
            
            while(!st.empty()&&nums2[i%n]>=st.top()) //we use modular arthemaitc to make it circular 
            {
                st.pop();
            }
            if (i<n ) if(!st.empty()) ng[i]=st.top();
            st.push(nums2[i%n]);
        }
        vector<int>a;
        for (int i = 0 ; i<nums1.size();i++)
        {
            for (int j = 0 ; j<n;j++)
            {
                if (nums1[i]==nums2[j])
                {
                    a[i]=ng[j];
                    break;
                }

            }
        }
        return a;
    }



    //Leetcode solution

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n =nums2.size();
        vector<int>ng(n,-1);
        stack<int>st;
        map<int,int>mp;
        for (int i = n -1 ; i >=0 ; i--) //Traverse backward  to fill stack with big vlaues first 
        {
            
            while(!st.empty()&&nums2[i]>=st.top()) 
            {
                st.pop();
            }
            if (i<n ) {if(!st.empty()) mp[nums2[i]]=st.top();
                      else mp[nums2[i]]=-1;
                      }
            st.push(nums2[i]);
        }
        vector<int>a(nums1.size(),-1);
        for (int i = 0 ; i<nums1.size();i++)
        {
            for (int j = 0 ; j<n;j++)
            {
                if (nums1[i]==nums2[j])
                {
                    a[i]=mp[nums2[j]];
                    
                }

            }
        }
        return a;
    }