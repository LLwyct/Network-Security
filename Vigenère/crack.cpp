#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

string toLowerCase(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i] = s[i] + ('a' - 'A');
        }
    }
    return s;
}


int main()
{
    map<char, double> _hash;
    _hash['a'] = 8.2;
    _hash['b'] = 1.5;
    _hash['c'] = 2.8;
    _hash['d'] = 4.2;
    _hash['e'] = 12.7;
    _hash['f'] = 2.2;
    _hash['g'] = 2.0;
    _hash['h'] = 6.1;
    _hash['i'] = 7.0;
    _hash['j'] = 0.1;
    _hash['k'] = 0.8;
    _hash['l'] = 4.0;
    _hash['m'] = 2.4;
    _hash['n'] = 6.8;
    _hash['o'] = 7.5;
    _hash['p'] = 1.9;
    _hash['q'] = 0.1;
    _hash['r'] = 6.0;
    _hash['s'] = 6.3;
    _hash['t'] = 9.0;
    _hash['u'] = 2.8;
    _hash['v'] = 1.0;
    _hash['w'] = 2.4;
    _hash['x'] = 2.0;
    _hash['y'] = 0.1;
    _hash['z'] = 0.1;
    //  �������Ĳ�ת����Сд
    string ciphertext; cin>>ciphertext; ciphertext = toLowerCase(ciphertext);
    // ָ���غϷ�������Կ����
    int length = ciphertext.length();
    // ��ǰƫ�����������ĸƥ����Ŀ
    int max_match_num = 0;
    // ���������Կ����
    int key_length = -1;
    for(int i=1;i<length;i++)
    {
        int equal_num = 0;
        for(int j=0;j<length;j++)
        {
            if(ciphertext[j] == ciphertext[(j+i)%length])
            {
                equal_num ++;
            }
        }
        if(equal_num > max_match_num)
        {
            max_match_num = equal_num;
            key_length = i;
        }
    }
    printf("��Կ����Ϊ%d\n", key_length);
    // ��Կ���ȼ������

    /* ----------------------------------------------------

    ����ÿһ��Կ������������ת������֪�����и���ĸ����Ƶ��
    ��������������ֵ������ܵĵ�ǰ��Կ�����Ķ�Ӧƫ����

    ---------------------------------------------------- */
    vector<int>ans;
    // ����ÿһ����Կ�������м���
    for(int i=1;i<=key_length;i++)
    {
        // ��ǰ��������ƫ���е�����ֵ
        double max_dj = 0;
        // ��ǰ��������ƫ�����������Ӧ��ƫ����
        int fl = -1;
        for(int k=0;k<26;k++)
        {
            // ������ĸ�ڵ�ǰΪk��ƫ���³��ֵĸ���
            double temp_probability[26];
            // ��ʼ��temp_probability
            for(int j=0;j<26;j++)
            {
                temp_probability[j] = 0.0;
            }
            // ��Ծ����
            int multiple = 0;
            while(i + multiple <= length)
            {
                int index = i + multiple;
                temp_probability[(ciphertext[index-1]+k-'a')%26] += 1.0;
                multiple += key_length;
            }
            for(int j=0;j<26;j++)
            {
                temp_probability[j] = temp_probability[j]*1.0/(length*1.0/key_length*1.0);
            }
            // ���
            double dj = 0;
            for(int j=0;j<26;j++)
            {
                dj += _hash['a'+j]/100 * temp_probability[j];
            }
            // ��ͬƫ�����µ����ֵ������¼ƫ����
            if(dj > max_dj)
            {
                max_dj = dj;
                fl = k;
            }
        }
        ans.push_back(fl);
    }
    // ת��Ϊ����
    string plaintext = ciphertext;
    for(int i=1;i<=6;i++)
    {
        int multiple = 0;
        while(i + multiple <= length)
        {
            int index = i + multiple;
            plaintext[index-1] = (plaintext[index-1] + ans[i-1] - 'a')%26 + 'a';
            multiple += key_length;
        }
    }
    cout<<"�����ǣ�\n"<<plaintext;
}

