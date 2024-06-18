import React from 'react';

const LabeledText = ({label, text, valueSize="text-5xl"}) => {
    return (
        <div className="mb-10">
            <div className="text-large font-bold text-gray-300">{label}</div>
            <div className={`${valueSize} text-white`}>{text}</div>
        </div>
    );
};

export default LabeledText;