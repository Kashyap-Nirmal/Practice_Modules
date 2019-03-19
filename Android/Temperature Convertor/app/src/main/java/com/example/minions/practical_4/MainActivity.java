package com.example.minions.practical_4;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Button;
import android.view.View;
import android.view.View.OnClickListener;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                double val1,val2,val3;
                String msg;
                EditText et = (EditText) findViewById(R.id.editText);
                EditText et2 = (EditText) findViewById(R.id.editText2);
                TextView tv = (TextView) findViewById(R.id.textView3);
                if(et.getText().toString().length()>=18 || et2.getText().toString().length()>=18){
                    tv.setVisibility(View.VISIBLE);
                    tv.setText("Max value reached.");
                }
                else{
                    if(!et.getText().toString().isEmpty() && et2.getText().toString().isEmpty()){
                        val1 = Double.parseDouble(et.getText().toString());
                        val2=(1.8*val1)+32;
                        msg=String.format("%.2f",val1)+" C = "+String.format("%.2f",val2)+" F";
                        tv.setVisibility(View.VISIBLE);
                    }
                    else if(!et2.getText().toString().isEmpty() && et.getText().toString().isEmpty()) {
                        val2 = Double.parseDouble(et2.getText().toString());
                        val1=(val2-32)*5.0/9;
                        msg=String.format("%.2f",val2)+" F = "+String.format("%.2f",val1)+" C";
                        tv.setVisibility(View.VISIBLE);
                    }
                    else{
                        val1 = Double.parseDouble(et.getText().toString());
                        val2 = Double.parseDouble(et2.getText().toString());
                        val3=1.8*val1+32;
                        msg=String.format("%.2f",val1)+" C = "+String.format("%.2f",val3)+" F\n"+String.format("%.2f",val2)+" F = "+String.format("%.2f",(val2-32)*5.0/9)+" C";
                        tv.setVisibility(View.VISIBLE);
                    }
                    tv.setText(msg);
                }
            }
        });
    }
}
